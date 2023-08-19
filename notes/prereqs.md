# Prerequisite Knowledge

Before diving into the project, it's important to have a solid understanding of the following concepts:

### C++
#### CMake
To set up our project build system, it's recommended to watch COMP6771 lecture 1.2 on CMake. 

#### Header Files and File Layout
Follow the established convention for organizing code between `.cpp` and `.hpp` files. We will define this convention during a meeting to ensure consistency. Additionally, learn about header guards (`#ifndef`) and pragmas to prevent multiple inclusions of the same header file.

#### Classes and Object-Oriented Concepts
Understanding classes and object-oriented programming (OOP) is crucial for this project. You can refer to [this YouTube video](https://www.youtube.com/watch?v=SiBw7os-_zI) to learn about:
- Fields, methods, constructors, and destructors
- Access specifiers: private, public, and protected
- Encapsulation, getters, and setters

### Namespaces
Familiarize yourself with how namespaces work in C++. We'll be creating our own Lox namespace to organize our code effectively.

### Standard Library
The C++ Standard Library provides many useful classes that we can leverage for our project. Review the example code and observe the use of classes like `std::any` and `std::unique_ptr<>`. Learn about their functionalities and how to use them in your code.

### Java (for Translating Concepts)
Having a basic understanding of Java will be helpful as Lox's core concepts will remain similar between the two languages. Focus on the keywords shared with C++, such as `public`, `private`, and `protected`.

Remember that you can learn and deepen your understanding of these concepts as you progress through the project.

## Getting Started

1. **Clone the Repository:** Begin by cloning the project repository to your local machine.

2. **Build Setup:** Follow the guidelines discussed in the COMP6771 lecture 1.2 to set up the project's build system using CMake. This will ensure a consistent and smooth build process.

3. **Code Organization:** Adhere to the agreed-upon convention for organizing code between header and source files. Utilize header guards (`#ifndef`) to prevent header inclusion issues.

4. **Object-Oriented Design:** As we implement the Lox interpreter, focus on creating classes that encapsulate the various components of the interpreter. Follow OOP principles to ensure modular and maintainable code.

5. **Namespace Usage:** Implement the Lox namespace to organize your code. This will help prevent naming conflicts and enhance the clarity of the codebase.

6. **Standard Library Usage:** As you encounter situations where the C++ Standard Library classes can simplify your code, feel free to integrate them. Remember to document your code to explain the purpose and usage of these classes.

7. **Java Comparison:** When working with Lox's concepts, refer to your basic understanding of Java to help you translate these concepts into C++ effectively.

## Further Learning

Throughout the project, if you encounter challenges or need to deepen your understanding, don't hesitate to explore additional resources online. Websites like [cppreference.com](https://en.cppreference.com/w/) and [cplusplus.com](http://www.cplusplus.com/) offer detailed information about C++ concepts and the Standard Library.

## Conclusion

By following the guidelines outlined in this documentation, you'll be well-equipped to contribute effectively to our group project. Remember that learning and collaboration are integral parts of the process, so don't hesitate to ask questions and share your insights with the team. Let's work together to build a robust and functional Lox interpreter in C++!
