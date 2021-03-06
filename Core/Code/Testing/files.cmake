# tests with no extra command line parameter
set(MODULE_TESTS
  mitkAccessByItkTest.cpp
  mitkCoreObjectFactoryTest.cpp
  mitkMaterialTest.cpp
  mitkActionTest.cpp
  mitkDispatcherTest.cpp
  mitkEnumerationPropertyTest.cpp
  mitkEventTest.cpp
  mitkFocusManagerTest.cpp
  mitkGenericPropertyTest.cpp
  mitkGeometry2DTest.cpp
  mitkGeometry3DTest.cpp
  mitkGeometry3DEqualTest.cpp
  mitkGeometryDataToSurfaceFilterTest.cpp
  mitkGlobalInteractionTest.cpp
  mitkImageEqualTest.cpp
  mitkImageDataItemTest.cpp
  mitkImageGeneratorTest.cpp
  mitkIOUtilTest.cpp
  mitkBaseDataTest.cpp
  mitkImportItkImageTest.cpp
  mitkGrabItkImageMemoryTest.cpp
  mitkInstantiateAccessFunctionTest.cpp
  mitkInteractorTest.cpp
  mitkLevelWindowTest.cpp
  mitkMessageTest.cpp
  mitkPixelTypeTest.cpp
  mitkPlaneGeometryTest.cpp
  mitkPointSetEqualTest.cpp
  mitkPointSetFileIOTest.cpp
  mitkPointSetTest.cpp
  mitkPointSetWriterTest.cpp
  mitkPointSetReaderTest.cpp
  mitkPointSetInteractorTest.cpp
  mitkPropertyTest.cpp
  mitkPropertyListTest.cpp
  mitkSlicedGeometry3DTest.cpp
  mitkSliceNavigationControllerTest.cpp
  mitkStateMachineTest.cpp
  mitkStateTest.cpp
  mitkSurfaceTest.cpp
  mitkSurfaceEqualTest.cpp
  mitkSurfaceToSurfaceFilterTest.cpp
  mitkTimeGeometryTest.cpp
  mitkTransitionTest.cpp
  mitkUndoControllerTest.cpp
  mitkVtkWidgetRenderingTest.cpp
  mitkVerboseLimitedLinearUndoTest.cpp
  mitkWeakPointerTest.cpp
  mitkTransferFunctionTest.cpp
  mitkStepperTest.cpp
  itkTotalVariationDenoisingImageFilterTest.cpp
  mitkRenderingManagerTest.cpp
  vtkMitkThickSlicesFilterTest.cpp
  mitkNodePredicateSourceTest.cpp
  mitkVectorTest.cpp
  mitkClippedSurfaceBoundsCalculatorTest.cpp
  mitkExceptionTest.cpp
  mitkExtractSliceFilterTest.cpp
  mitkLogTest.cpp
  mitkImageDimensionConverterTest.cpp
  mitkLoggingAdapterTest.cpp
  mitkUIDGeneratorTest.cpp
  mitkShaderRepositoryTest.cpp
  mitkPlanePositionManagerTest.cpp
  mitkAffineTransformBaseTest.cpp
  mitkPropertyAliasesTest.cpp
  mitkPropertyDescriptionsTest.cpp
  mitkPropertyExtensionsTest.cpp
  mitkPropertyFiltersTest.cpp
  mitkTinyXMLTest.cpp
  mitkRawImageFileReaderTest.cpp
  mitkInteractionEventTest.cpp
  mitkLookupTableTest.cpp
  mitkSTLFileReaderTest.cpp

  ################## DISABLED TESTS #################################################
  #mitkAbstractTransformGeometryTest.cpp #seems as tested class mitkExternAbstractTransformGeometry doesnt exist any more
  #mitkStateMachineContainerTest.cpp #rewrite test, indirect since no longer exported Bug 14529
  #mitkRegistrationBaseTest.cpp #tested class  mitkRegistrationBase doesn't exist any more
  #mitkSegmentationInterpolationTest.cpp #file doesn't exist!
  #mitkPipelineSmartPointerCorrectnessTest.cpp #file doesn't exist!
  #mitkITKThreadingTest.cpp #test outdated because itk::Semaphore was removed from ITK
  #mitkAbstractTransformPlaneGeometryTest.cpp #mitkVtkAbstractTransformPlaneGeometry doesn't exist any more
  #mitkTestUtilSharedLibrary.cpp #Linker problem with this test...
  #mitkTextOverlay2DSymbolsRenderingTest.cpp #Implementation of the tested feature is not finished yet. Ask Christoph or see bug 15104 for details.
)

# test with image filename as an extra command line parameter
set(MODULE_IMAGE_TESTS
  mitkImageTimeSelectorTest.cpp #only runs on images
  mitkImageAccessorTest.cpp #only runs on images
  mitkDataNodeFactoryTest.cpp #runs on all types of data
)

set(MODULE_SURFACE_TESTS
  mitkSurfaceVtkWriterTest.cpp #only runs on surfaces
  mitkDataNodeFactoryTest.cpp #runs on all types of data
)

# list of images for which the tests are run
set(MODULE_TESTIMAGES
  US4DCyl.nrrd
  Pic3D.nrrd
  Pic2DplusT.nrrd
  BallBinary30x30x30.nrrd
  Png2D-bw.png
)
set(MODULE_TESTSURFACES
  binary.stl
  ball.stl
)

set(MODULE_CUSTOM_TESTS
    mitkDataStorageTest.cpp
    mitkDataNodeTest.cpp
    mitkDicomSeriesReaderTest.cpp
    mitkDICOMLocaleTest.cpp
    mitkEventMapperTest.cpp
    mitkEventConfigTest.cpp
    mitkNodeDependentPointSetInteractorTest.cpp
    mitkStateMachineFactoryTest.cpp
    mitkPointSetLocaleTest.cpp
    mitkImageTest.cpp
    mitkImageWriterTest.cpp
    mitkImageVtkMapper2DTest.cpp
    mitkImageVtkMapper2DLevelWindowTest.cpp
    mitkImageVtkMapper2DOpacityTest.cpp
    mitkImageVtkMapper2DResliceInterpolationPropertyTest.cpp
    mitkImageVtkMapper2DColorTest.cpp
    mitkImageVtkMapper2DSwivelTest.cpp
    mitkImageVtkMapper2DTransferFunctionTest.cpp
    mitkImageVtkMapper2DLookupTableTest.cpp
    mitkSurfaceVtkMapper3DTest
    mitkSurfaceVtkMapper3DTexturedSphereTest.cpp
    mitkSurfaceGLMapper2DColorTest.cpp
    mitkSurfaceGLMapper2DOpacityTest.cpp
    mitkVolumeCalculatorTest.cpp
    mitkLevelWindowManagerTest.cpp
    mitkPointSetVtkMapper2DTest.cpp
    mitkPointSetVtkMapper2DImageTest.cpp
    mitkPointSetVtkMapper2DGlyphTypeTest.cpp
    mitkPointSetVtkMapper2DTransformedPointsTest.cpp
    mitkLabelOverlay3DRendering2DTest.cpp
    mitkLabelOverlay3DRendering3DTest.cpp
    mitkTextOverlay2DRenderingTest.cpp
    mitkTextOverlay2DLayouterRenderingTest.cpp
    mitkTextOverlay3DRendering2DTest.cpp
    mitkTextOverlay3DRendering3DTest.cpp
    mitkTextOverlay3DColorRenderingTest.cpp
    mitkVTKRenderWindowSizeTest.cpp
    mitkMultiComponentImageDataComparisonFilterTest.cpp
    mitkImageToItkTest.cpp
    mitkImageSliceSelectorTest.cpp
)

set(MODULE_RESOURCE_FILES
  Interactions/AddAndRemovePoints.xml
  Interactions/globalConfig.xml
  Interactions/StatemachineTest.xml
  Interactions/StatemachineConfigTest.xml
)

# Create an artificial module initializing class for
# the usServiceListenerTest.cpp
usFunctionGenerateExecutableInit(testdriver_init_file
                                 IDENTIFIER ${MODULE_NAME}TestDriver
                                )

# Embed the resources
set(testdriver_resources )
usFunctionEmbedResources(testdriver_resources
                         EXECUTABLE_NAME ${MODULE_NAME}TestDriver
                         ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Resources
                         FILES ${MODULE_RESOURCE_FILES}
                        )

set(TEST_CPP_FILES ${testdriver_init_file} ${testdriver_resources})
