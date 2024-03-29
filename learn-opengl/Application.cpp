//#include "glad/glad.h"
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include "Shader.h"
//#include <stb_image.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "Camera.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void processInput(GLFWwindow* window);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//unsigned int loadTexture(char const* path);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//float deltaTime = 0.0f; // Time between current frame and last frame
//float lastFrame = 0.0f; // Time of last frame
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse(true);
//
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//Camera camera;
//
//int preLoader()
//{
//	// Initialize GLFW, provide versioning and core profile usage.
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	
//	// Create a window object that OpenGL can render to.
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	// Setting the previously created window object as the current context.
//	// Meaning, any future drawing, resizing, etc. will effect this window object.
//	glfwMakeContextCurrent(window);
//
//	// Set a callback function to handle window resizing dynamically.
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// Initialize GLAD by providing it the address of OpenGL functions to use at runtime.
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//
//	Shader lightingShader("C:/dev/learn-opengl/learn-opengl/multiple_lights.vs",
//		"C:/dev/learn-opengl/learn-opengl/multiple_lights.fs");
//
//	Shader lightCubeShader("C:/dev/learn-opengl/learn-opengl/light_cube.vs",
//		"C:/dev/learn-opengl/learn-opengl/light_cube.fs");
//	
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//	   glm::vec3(0.0f,  0.0f,  0.0f),
//	   glm::vec3(2.0f,  5.0f, -15.0f),
//	   glm::vec3(-1.5f, -2.2f, -2.5f),
//	   glm::vec3(-3.8f, -2.0f, -12.3f),
//	   glm::vec3(2.4f, -0.4f, -3.5f),
//	   glm::vec3(-1.7f,  3.0f, -7.5f),
//	   glm::vec3(1.3f, -2.0f, -2.5f),
//	   glm::vec3(1.5f,  2.0f, -2.5f),
//	   glm::vec3(1.5f,  0.2f, -1.5f),
//	   glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	glm::vec3 pointLightPositions[] = {
//		glm::vec3(0.7f,  0.2f,  2.0f),
//		glm::vec3(2.3f, -3.3f, -4.0f),
//		glm::vec3(-4.0f,  2.0f, -12.0f),
//		glm::vec3(0.0f,  0.0f, -3.0f)
//	};
//
//	unsigned int VBO, cubeVAO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(cubeVAO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//	// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//	unsigned int lightCubeVAO;
//	glGenVertexArrays(1, &lightCubeVAO);
//	glBindVertexArray(lightCubeVAO);
//
//	// we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	
//	unsigned int diffuseMap = loadTexture("C:/Users/eatho/Downloads/container2.png");
//	unsigned int specularMap = loadTexture("C:/Users/eatho/Downloads/container2_specular.png");
//
//	lightingShader.use();
//	lightingShader.setInt("material.diffuse", 0);
//	lightingShader.setInt("material.specular", 1);
//
//	// Main window loop.
//	while (!glfwWindowShouldClose(window))
//	{
//		// Calculate per-frame time logic via deltaTime.
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// Process input "keystroke reading/reaction, etc"
//		processInput(window);
//		glfwSetCursorPosCallback(window, mouse_callback);
//		glfwSetScrollCallback(window, scroll_callback);
//		
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// be sure to activate shader when setting uniforms/drawing objects
//		lightingShader.use();
//		lightingShader.setVec3("viewPos", camera.Position);
//		lightingShader.setFloat("material.shininess", 32.0f);
//
//		/*
//		   Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
//		   the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
//		   by defining light types as classes and set their values in there, or by using a more efficient uniform approach
//		   by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
//		*/
//		// directional light
//		lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//		lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//		// point light 1
//		lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
//		lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setFloat("pointLights[0].constant", 1.0f);
//		lightingShader.setFloat("pointLights[0].linear", 0.09f);
//		lightingShader.setFloat("pointLights[0].quadratic", 0.032f);
//		// point light 2
//		lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
//		lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setFloat("pointLights[1].constant", 1.0f);
//		lightingShader.setFloat("pointLights[1].linear", 0.09f);
//		lightingShader.setFloat("pointLights[1].quadratic", 0.032f);
//		// point light 3
//		lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
//		lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setFloat("pointLights[2].constant", 1.0f);
//		lightingShader.setFloat("pointLights[2].linear", 0.09f);
//		lightingShader.setFloat("pointLights[2].quadratic", 0.032f);
//		// point light 4
//		lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
//		lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setFloat("pointLights[3].constant", 1.0f);
//		lightingShader.setFloat("pointLights[3].linear", 0.09f);
//		lightingShader.setFloat("pointLights[3].quadratic", 0.032f);
//		// spotLight
//		lightingShader.setVec3("spotLight.position", camera.Position);
//		lightingShader.setVec3("spotLight.direction", camera.Front);
//		lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//		lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.setFloat("spotLight.constant", 1.0f);
//		lightingShader.setFloat("spotLight.linear", 0.09f);
//		lightingShader.setFloat("spotLight.quadratic", 0.032f);
//		lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
//		lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
//
//		// view/projection transformations
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		lightingShader.setMat4("projection", projection);
//		lightingShader.setMat4("view", view);
//
//		// world transformation
//		glm::mat4 model = glm::mat4(1.0f);
//		lightingShader.setMat4("model", model);
//
//		// bind diffuse map
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffuseMap);
//		// bind specular map
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, specularMap);
//
//		// render containers
//		glBindVertexArray(cubeVAO);
//		for (unsigned int i = 0; i < 10; i++)
//		{
//			// calculate the model matrix for each object and pass it to shader before drawing
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			lightingShader.setMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		// also draw the lamp object(s)
//		lightCubeShader.use();
//		lightCubeShader.setMat4("projection", projection);
//		lightCubeShader.setMat4("view", view);
//
//		// we now draw as many light bulbs as we have point lights.
//		glBindVertexArray(lightCubeVAO);
//		for (unsigned int i = 0; i < 4; i++)
//		{
//			model = glm::mat4(1.0f);
//			model = glm::translate(model, pointLightPositions[i]);
//			model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//			lightCubeShader.setMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::UP, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//		camera.ProcessKeyboard(Camera_Movement::DOWN, deltaTime);
//}
//
//unsigned int loadTexture(char const* path)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//	int width, height, nrComponents;
//	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//	if (data)
//	{
//		GLenum format;
//		if (nrComponents == 1)
//			format = GL_RED;
//		else if (nrComponents == 3)
//			format = GL_RGB;
//		else if (nrComponents == 4)
//			format = GL_RGBA;
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		stbi_image_free(data);
//	}
//	else
//	{
//		std::cout << "Texture failed to load at path: " << path << std::endl;
//		stbi_image_free(data);
//	}
//
//	return textureID;
//}

// !!!!====================================== Snippet Graveyard ==============================================!!!!

// Translation Matrix setup to transform a matrix.
// glm::mat4 trans = glm::mat4(1.0f);
// trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
// trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
// trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
// glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));*/

// Passing in constantly changing color to a shader in order to change green colors.
// float timeValue = glfwGetTime();
// float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
// int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");*/
// glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);


// Array of vec3 - cube positions to render cubes to on screen. =============================================
//glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f, 0.0f, 0.0f),
//		glm::vec3(2.0f, 5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f, 3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f, 2.0f, -2.5f),
//		glm::vec3(1.5f, 0.2f, -1.5f),
//		glm::vec3(-1.3f, 1.0f, -1.5f)
//};
// 
//for (unsigned int i = 0; i < 10; i++)
//{
//	// calculate the model matrix for each object and pass it to shader before drawing
//	glm::mat4 model = glm::mat4(1.0f);
//	model = glm::translate(model, cubePositions[i]);
//	float angle = 20.0f * i;
//	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(1.0f, 0.3f, 0.5f));
//	ourShader.setMat4("model", model);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//}


// Load and generate a texture. ==============================================================================
//int width, height, nrChannels;
//stbi_set_flip_vertically_on_load(true);
//unsigned char* data = stbi_load("C:/Users/eatho/Downloads/container.jpg", &width, &height, &nrChannels, 0);
//if (data)
//{
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glGenerateMipmap(GL_TEXTURE_2D);
//}
//else
//{
//	std::cout << "Failed to load texture" << std::endl;
//}
//stbi_image_free(data);
//
//glGenTextures(1, &texture2);
//glBindTexture(GL_TEXTURE_2D, texture2);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//data = stbi_load("C:/Users/eatho/Downloads/awesomeface.png", &width, &height, &nrChannels, 0);
//if (data)
//{
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//	glGenerateMipmap(GL_TEXTURE_2D);
//}
//else
//{
//	std::cout << "Failed to load texture" << std::endl;
//}
//stbi_image_free(data);


// Bind textures on texture units. =======================================================================
//glActiveTexture(GL_TEXTURE0);
//glBindTexture(GL_TEXTURE_2D, texture1);
//glActiveTexture(GL_TEXTURE1);
//glBindTexture(GL_TEXTURE_2D, texture2);


// Element buffer array setup.     =======================================================================
//unsigned int EBO;
//glGenBuffers(1, &EBO);
//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


// Indicies used to render two triangles over a square (4 coordinates). ==================================
//unsigned int indices[] = {
//		0,1,3, // first triangle
//		1,2,3 // second triangle
//};

// Texture Rendering setup.
//unsigned int texture1, texture2;
//glGenTextures(1, &texture1);
//glBindTexture(GL_TEXTURE_2D, texture1);
//// Set texture wrapping/filtering options on the currently bound texture.
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//ourShader.use();
//ourShader.setInt("texture1", 0);
//ourShader.setInt("texture2", 1);