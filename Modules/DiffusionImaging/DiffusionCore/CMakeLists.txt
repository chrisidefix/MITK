
MITK_CREATE_MODULE( DiffusionCore
  SUBPROJECTS MITK-DTI
  INCLUDE_DIRS Algorithms Algorithms/Reconstruction Algorithms/Registration Algorithms/Reconstruction/MultishellProcessing DicomImport IODataStructures/DiffusionWeightedImages IODataStructures/QBallImages IODataStructures/TensorImages IODataStructures Rendering ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS MitkMapperExt PlanarFigure ImageExtraction SceneSerializationBase
  PACKAGE_DEPENDS VTK|vtkFiltersProgrammable ITK|ITKDistanceMap+ITKRegistrationCommon+ITKLabelVoting+ITKVTK Boost
  WARNINGS_AS_ERRORS
)

add_subdirectory(Testing)
