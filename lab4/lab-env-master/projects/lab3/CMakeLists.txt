#--------------------------------------------------------------------------
# lab3 project
#--------------------------------------------------------------------------

PROJECT(lab3)
FILE(GLOB lab3_headers code/*.h)
FILE(GLOB lab3_sources code/*.cc)

SET(files_lab3 ${lab3_headers} ${lab3_sources})
SOURCE_GROUP("lab3" FILES ${files_lab3})

ADD_EXECUTABLE(lab3 ${files_lab3})
TARGET_LINK_LIBRARIES(lab3 core render MeshResource Texture ShaderResource)
ADD_DEPENDENCIES(lab3 core render MeshResource Texture ShaderResource)