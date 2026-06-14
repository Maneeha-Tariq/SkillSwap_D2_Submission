cmake_minimum_required(VERSION 4.0)
project(dsaV1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dsaV1
        ArrayVisualizer.h
        AVL.h
        BitManipVisualizer.h
        BST.h
        BTNode.h
        COLORS.h
        Cursor.h
        Data.h
        DPVisualizer.h
        GraphVisualizer.h
        HashVisualizer.h
        Interface.h
        KEYS.h
        mainFile.cpp
        MatrixVisualizer.h
        NumberTheoryVisualizer.h
        QueueVisualizer.h
        recursionBacktrackingVisualizer.h
        ScreenUtil.h
        SortingVisualizer.h
        SoundManager.h
        StackVisualizer.h
        StringVisualizer.h
        testField.cpp
        TreeVisualizer.h
        TrieVisualizer.h
        Widget.h)
