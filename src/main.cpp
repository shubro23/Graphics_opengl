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
    VkInstance instance;

    VkInstanceCreateInfo Inst{};//This way we create an instances as instance is a struct type we tend to give default value as 0 untill changed

    Inst.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;//default value
    Inst.pNext=nullptr;
    Inst.flags=0;
    Inst.pApplicationInfo=nullptr;
    Inst.enabledLayerCount=0;
    Inst.ppEnabledLayerNames=nullptr;
    Inst.enabledExtensionCount=0;
    Inst.ppEnabledExtensionNames=nullptr;

    if(!vkCreateInstance(&Inst,nullptr,&instance))//checking for vksucess if not then we have to change, assret will be issued otherwise
    {
        cout << "Vulkan instance created successfully!\n";


        while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        }
    }
    vkDestroyInstance(instance,nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}