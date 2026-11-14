#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
    if(!glfwInit()){
        throw runtime_error("Failed to initilize gflw");    
    }
    glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);//not for vulkan
    
    GLFWwindow* window=glfwCreateWindow(600, 300,"My_first_vulkan",nullptr,nullptr);
    while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
}
    glfwDestroyWindow(window);
    glfwTerminate();
}