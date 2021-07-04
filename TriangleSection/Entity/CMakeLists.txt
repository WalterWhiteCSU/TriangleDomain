# 将文件夹下所有文件添加进来
aux_source_directory(. triangle_domain_entity)

# 编译成库文件
add_library(TriangleDomainEntity ${triangle_domain_entity})