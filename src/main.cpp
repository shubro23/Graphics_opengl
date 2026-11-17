#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include<vector>
using namespace std;


int main(){

    uint32_t device_count=0;
    
    VkPhysicalDeviceProperties props{};


    if(!glfwInit()){
        throw runtime_error("Failed to initilize gflw");    
    }
    glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);//not for vulkan
    
    GLFWwindow* window=glfwCreateWindow(600, 300,"My_first_vulkan",nullptr,nullptr);
    VkInstance instance;

    VkInstanceCreateInfo Inst{};//Inst is the configuration struct (blueprint), while instance will hold the created Vulkan object

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
        
        
        vkEnumeratePhysicalDevices(instance,&device_count,nullptr);

        vector<VkPhysicalDevice> devices(device_count);
        vkEnumeratePhysicalDevices(instance,&device_count,devices.data());

      
        for(uint32_t i=0 ; i<device_count; i++)
        {
            vkGetPhysicalDeviceProperties(devices[i],&props);
            cout<<props.deviceName<<'\n';

        }
        

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }


    }
    vkDestroyInstance(instance,nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}