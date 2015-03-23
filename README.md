# libffc
Free Foundation Classes

This is an open source library designed for compiling MFC/ATL applications by gcc.

There are lots of existed projects based on MFC/ATL all over the world. However, it is not easy, or maybe impossible, to migrate them to other OS, such as Linux. I tried to build MFC source by gcc but failed for that many Microsoft specified compiler features are needed in the build process. Moreover, the license of MFC/ATL is another problem. Finally, I decided to write this MFC/ATL compatible open source library from scratch.

Since MFC was created by Microsoft before many C++ standards, Some design in MFC is not so preferable. In this project, I have been trying to use some new C++ technology to reimplement MFC, as well as ATL, in order to make it more efficient or elegant.

I found there is another open source project called OFC (Open Foundation Classes). But it seems that there is not any update since 2004. And I try to start this new project but not based on OFC, because some of my designs are different from OFC.

Any sugguestion is welcome to: yanlinlin82(at)gmail.com
