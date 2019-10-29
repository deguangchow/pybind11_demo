ECHO ======== Check CppCheck Start ========

cppcheck --enable=warning,performance --inconclusive pybind11_demo test > cppcheck.log

ECHO ======== Check CppCheck Result ========