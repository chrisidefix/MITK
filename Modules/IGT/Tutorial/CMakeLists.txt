add_executable(mitkIGTTutorialStep1 mitkIGTTutorialStep1.cpp)
mitk_use_modules(TARGET mitkIGTTutorialStep1 MODULES MitkIGT MitkDataTypesExt)

add_executable(mitkIGTTutorialStep2 mitkIGTTutorialStep2.cpp)
mitk_use_modules(TARGET mitkIGTTutorialStep2 MODULES MitkIGT MitkDataTypesExt)
