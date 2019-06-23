#version 330 core
layout (location = 0) out vec4 color;
layout (location = 1) out vec4 BrightColor;

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float shiness;
};

struct DirLight {
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {
	 vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 outColor;
in vec3 fragPos;
in vec3 norm;
in vec4 lightSpacePos;
in vec2 uv;
in mat3 TBN;

uniform sampler2D shadowMap;
uniform sampler2D diffuseTex;
uniform sampler2D specularTex;
uniform sampler2D normalMap;

uniform Material material;

uniform bool receiveShadows;
uniform bool hasDiffuseMap;
uniform bool hasSpecularMap;
uniform bool hasNormalMap;

uniform vec3 viewPos;

uniform DirLight dirLight;

uniform float transparency;
uniform float reflectivnes;

#define MAX_POINT_LIGHTS 4
uniform int pointLightsCount;
uniform PointLight pointLights[MAX_POINT_LIGHTS];

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir);

uniform vec3 cameraPos;
uniform samplerCube skybox;


void main()
{
    vec3 result = material.diffuse;
	if(hasDiffuseMap)
	{
		result *= texture(diffuseTex, uv).rgb;
	}
	
	vec3 I = normalize(fragPos - cameraPos);
    vec3 R = reflect(I, normalize(norm));
    result = mix(result,texture(skybox, R).rgb, reflectivnes);



	
	
    float brightness = dot(result, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(result, transparency);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, transparency);
    color = vec4(result, transparency);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir){
	
	vec3 lightDir = normalize(-light.direction);

	float diff = max(dot(normal, lightDir), 0.0f);
	
	//Phong model
	//vec3 reflectDir = reflect(-lightDir, normal);
	//float spec = pow(max(dot(reflectDir, viewDir), 0.0), material.shiness);

	//Blinn-Phong
	vec3 halfwayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shiness);

	vec3 I = normalize(fragPos - cameraPos);
    vec3 R = reflect(I, norm);
	
	vec3 ambient = light.ambient * material.ambient;
	vec3 diffuse = light.diffuse * material.diffuse * diff;
	vec3 specular = light.specular * material.specular * spec;

	if(hasSpecularMap)
		specular *= texture(specularTex, uv).rgb;
	if(hasDiffuseMap){
		ambient *= texture(diffuseTex, uv).rgb;
		diffuse *= texture(diffuseTex, uv).rgb;
	}
	mix(diffuse, texture(skybox,R).rgb, reflectivnes);
	diffuse = texture(skybox,R).rgb;

	vec3 projCoords = lightSpacePos.xyz / lightSpacePos.w;
	projCoords = projCoords * 0.5 + 0.5;

	float closestDepth = texture(shadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z;

	float shadow = 0.0;
	if(receiveShadows)
	{
		float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.003);  
		vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
		for(int x = -2; x <= 2; x++){
			for(int y = -2; y <=2; y++){
				float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x,y) * texelSize).r;
				shadow += currentDepth - bias > pcfDepth ? 1 : 0;
			}
		}
		shadow /= 25;

		if(projCoords.z > 1.0)
			shadow = 0;
	}
	return (ambient + (1.0 - shadow) * (diffuse + specular));
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir){
	
	vec3 lightDir = normalize(light.position - fragPos);

	float diff = max(dot(normal, lightDir), 0.0);

	//Phong model
	//vec3 reflectDir = reflect(-lightDir, normal);
	//float spec = pow(max(dot(reflectDir, viewDir), 0.0), material.shiness);

	//Blinn-Phong
	vec3 halfwayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shiness);

	vec3 ambient = light.ambient * material.ambient;
	vec3 diffuse = light.diffuse * material.diffuse * diff;
	vec3 specular = light.specular * material.specular * spec;

	if(hasSpecularMap)
		specular *= texture(specularTex, uv).rgb;
	if(hasDiffuseMap){
		ambient *= texture(diffuseTex, uv).rgb;
		diffuse *= texture(diffuseTex, uv).rgb;
	}

	float dist = length(fragPos - light.position);
	float attentuation = 1 /(light.constant + light.linear * dist + light.quadratic * dist * dist);

	ambient *= attentuation;
	diffuse *= attentuation;
	specular *= attentuation;
	
	return (ambient + (diffuse + specular));
}
