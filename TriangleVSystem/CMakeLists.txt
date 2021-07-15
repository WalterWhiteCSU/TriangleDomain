# 将文件夹下所有文件添加进来
aux_source_directory(. triangle_v_util)

aux_source_directory(./Tree triangle_v_tree)

# 编译成库文件
add_library(TriangleV ${triangle_v_util} ${triangle_v_tree})