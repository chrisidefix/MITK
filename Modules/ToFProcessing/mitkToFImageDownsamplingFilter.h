/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __mitkToFImageDownsamplingFilter_h
#define __mitkToFImageDownsamplingFilter_h

//MITK includes
#include <mitkImage.h>
#include "mitkImageToImageFilter.h"
#include "mitkToFProcessingExports.h"
// ITK includes
#include "itkImage.h"

namespace mitk
{
  /**
  * @brief Reduces the resolution of a ToF distance image. Although it is meant to be used for ToF distance images, it should work
  * for any 2D or 3D images. The dimensions (in pixels) of the desired image are taken as input parameters, and an image with these
  * specified dimensions is created. 
  *
  * @ingroup SurfaceFilters
  * @ingroup ToFProcessing
  */

	class mitkToFProcessing_EXPORT ToFImageDownsamplingFilter : public ImageToImageFilter
	{
	public:
		mitkClassMacro(ToFImageDownsamplingFilter, ImageToImageFilter); 
		itkNewMacro(Self);	

		itkSetMacro(ResampledX,double); 
		itkGetMacro(ResampledX,double); 

		itkSetMacro(ResampledY,double); 
		itkGetMacro(ResampledY,double); 

		itkSetMacro(ResampledZ,double); 
		itkGetMacro(ResampledZ,double); 


	protected:	 
		/*!
    \brief Standard constructor
    */
		ToFImageDownsamplingFilter();
		
    /*!
    \brief Standard destructor
    */
    ~ToFImageDownsamplingFilter();	
    
     /*!
    \brief Method generating the output of this filter. Called in the updated process of the pipeline.
    This method calls the AccessFixedDimensionByItk class with the ItkImageResampling function below 
    */
    virtual void GenerateData();		
    
     /*!
    \brief Templated method for ITK image type which performs the resampling with an itk filter.
    \param itkImage is the input to the filter converted to ITK format
    \param TPixel is a pixel type such as float or char or double
    \param VImageDimension is the image dimension (2D or 3D)
    */
    template<typename TPixel, unsigned int VImageDimension>
    void ItkImageResampling( itk::Image<TPixel,VImageDimension>* itkImage );

		double m_ResampledX;///<  length of x dimension of output image in pixels
		double m_ResampledY;///<  length of y dimension of output image in pixels
		double m_ResampledZ;///<  length of z dimension of output image in pixels (if 2D, default is set to 1) 
    
	};
}// end namespace mitk 
#endif