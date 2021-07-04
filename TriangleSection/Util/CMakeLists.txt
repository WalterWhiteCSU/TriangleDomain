# 将文件夹下所有文件添加进来
aux_source_directory(. triangle_domain_util)

# 编译成库文件
add_library(TriangleDomainUtil ${triangle_domain_util} TriangleVFunc.cpp TriangleVFunc.h)