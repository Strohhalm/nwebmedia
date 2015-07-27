

add_library(NWebMedia SHARED NMedViewDashBoard.cpp NMedViewDashBoard.h NWebMedia.h NViewMediaFactory.cpp NViewMediaFactory.h NWebMediaEntryPoint.cpp)

target_link_libraries(NWebMedia PUBLIC NBase NServiceClient NWeb ${LIBARIES} ${WT_LIBRARIES})