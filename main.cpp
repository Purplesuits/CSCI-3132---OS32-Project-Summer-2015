#include <iostream>

#include "OS32Memory.h"
#include "UI.h"

/**
 * Returns the size of the kernel heap.
 * TODO this doesn't use the config file :-)
 */
size_t getKernalHeapSize() {
    return 1024 * 1024 * 10; // 10 MB
}

/**
 * Returns the size of the user heap
 * TODO this ddoesn't use the config file
 */
size_t getUserHeapSize() {
    return 1024 * 1024 * 2; // 2 MB
}

int main(int argc, char *argv[]) {
    std::cout << "Starting OS32" << std::endl;

    OS32Memory& memory = OS32Memory::getInstance();
    memory.initialize(getKernalHeapSize(), getUserHeapSize());

    UI ui;
    ui.startUI();

    std::cout << "Exiting OS32" << std::endl;

    return 0;
}
