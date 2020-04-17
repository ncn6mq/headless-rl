cdef extern from "Rectangle.cpp":
    pass

cdef extern from "Ball.h" namespace "rl":
    cdef cppclass Rectangle:
