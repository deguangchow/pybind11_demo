///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    pybind11_demo : Python 2.7(3.7)
///
///    \author   deguangchow
///    \version  1.0
///    \2019/10/29

#include "pybind11/pybind11.h"
namespace py = pybind11;

int add1(int a, int b) {
    return a + b;
}

int add2(int a, int b) {
    return a + b;
}

int add3(int a, int b) {
    return a + b;
}

//PYBIND11_MODULE 申明的命名空间 “pybind11_demo”, 即为 import 的.pyd文件名
PYBIND11_MODULE(pybind11_demo, m) {
    m.doc() = "pybind11 example module";

    // Add bindings here
    m.def("foo", []() {
        return "Hello World!";
    });
    m.def("foo2", []() {
        return "This is foo2!\n";
    });
    m.def("add", [](int a, int b) {
        return a + b;
    });
    m.def("sub", [](int a, int b) {
        return a - b;
    });
    m.def("mul", [](int a, int b) {
        return a * b;
    });
    m.def("div", [](int a, int b)->float {
        if (fabs(b) < 1e-10) {
            return 0.0;
        }
        return static_cast<float>(a) / b;
    });

    //fucntion name, function point, discribe.
    m.def("add1", &add1, "add1()");
    //keyword arguments
    m.def("add2", &add2, "add2()", py::arg("a"), py::arg("b"));
    //default arguments
    m.def("add3", &add3, "add3()", py::arg("a") = 10, py::arg("b") = 5);

    //Exporting variables
    m.attr("num1") = 100;
    py::object world = py::cast("World");
    m.attr("what") = world;
}

