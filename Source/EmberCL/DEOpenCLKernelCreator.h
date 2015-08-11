#pragma once

#include "EmberCLPch.h"
#include "EmberCLStructs.h"
#include "EmberCLFunctions.h"

/// <summary>
/// DEOpenCLKernelCreator class.
/// </summary>

//#define ROW_ONLY_DE 1

namespace EmberCLns
{
/// <summary>
/// Kernel creator for density filtering.
/// This implements both basic log scale filtering
/// as well as the full flam3 density estimation filtering
/// in OpenCL.
/// Several conditionals are present in the CPU version. They
/// are stripped out of the kernels and instead a separate kernel
/// is created for every possible case.
/// If the filter width is 9 or less, then the entire process can be
/// done in shared memory which is very fast.
/// However, if the filter width is greater than 9, shared memory is not
/// used and all filtering is done directly with main global VRAM. This
/// ends up being not much faster than doing it on the CPU.
/// String members are kept for the program source and entry points
/// for each version of the program.
/// </summary>
class EMBERCL_API DEOpenCLKernelCreator
{
public:
	DEOpenCLKernelCreator(bool doublePrecision, bool nVidia);

	//Accessors.
	string LogScaleAssignDEKernel();
	string LogScaleAssignDEEntryPoint();
	string GaussianDEKernel(size_t ss, uint filterWidth);
	string GaussianDEEntryPoint(size_t ss, uint filterWidth);

	//Miscellaneous static functions.
	static uint MaxDEFilterSize();
	static double SolveMaxDERad(uint maxBoxSize, double desiredFilterSize, double ss);
	static uint SolveMaxBoxSize(uint localMem);

private:
	//Kernel creators.
	string CreateLogScaleAssignDEKernelString();
	string CreateGaussianDEKernel(size_t ss);
	string CreateGaussianDEKernelNoLocalCache(size_t ss);

	string m_LogScaleAssignDEKernel;
	string m_LogScaleAssignDEEntryPoint;

	string m_GaussianDEWithoutSsKernel;
	string m_GaussianDEWithoutSsEntryPoint;

	string m_GaussianDESsWithScfKernel;
	string m_GaussianDESsWithScfEntryPoint;

	string m_GaussianDESsWithoutScfKernel;
	string m_GaussianDESsWithoutScfEntryPoint;

	string m_GaussianDEWithoutSsNoCacheKernel;
	string m_GaussianDEWithoutSsNoCacheEntryPoint;

	string m_GaussianDESsWithScfNoCacheKernel;
	string m_GaussianDESsWithScfNoCacheEntryPoint;

	string m_GaussianDESsWithoutScfNoCacheKernel;
	string m_GaussianDESsWithoutScfNoCacheEntryPoint;

	bool m_DoublePrecision;
	bool m_NVidia;
};
}
