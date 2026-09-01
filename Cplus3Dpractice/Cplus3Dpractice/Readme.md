<HTML>
<HEAD>
<META NAME="GENERATOR" Content="Microsoft Visual Studio">
<TITLE> Read me for this project</TITLE>
</HEAD>
<BODY>
In your properties of your project update output Directory to point to Bin\ and then the rest of your platform configuration as it is. Modify intermediate
directory to be Intermediate\ then the rest. Make sure the C++ language standard is set to 20 then under C++ tab go to the multi processor compilation field and set it to yes 
this last step lets you compile the program faster.
in your IDE you can click local windows debugger to run the program if it runs with code 0 initially you have done it right.
header files will be going in the include folder whereas the source folder will contain the actual classes.
on methods that are unimplemented you can right click them and select create declaration/definition to create an empty shell method.
under vc++directories under include directories make sure you edit to include DX3D/Include and DX3D/Source and apply the changes to the project.
you want all the rendersystem stuff in source so that its not exposed in the public API
in the project properties under linker -> input additional input add the library d3d11.lib and apply those changes
</BODY>
</HTML>
