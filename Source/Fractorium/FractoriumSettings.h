#pragma once

#include "FractoriumPch.h"

/// <summary>
/// FractoriumSettings class.
/// </summary>

#define EARLYCLIP            "render/earlyclip"
#define YAXISUP				 "render/yaxisup"
#define TRANSPARENCY         "render/transparency"
#define OPENCL               "render/opencl"
#define DOUBLEPRECISION		 "render/dp64"
#define CONTUPDATE			 "render/continuousupdate"
#define SHOWALLXFORMS	     "render/dragshowallxforms"
#define DEVICES				 "render/devices"
#define THREADCOUNT          "render/threadcount"
#define CPUDEFILTER			 "render/cpudefilter"
#define OPENCLDEFILTER       "render/opencldefilter"
#define CPUSUBBATCH		     "render/cpusubbatch"
#define OPENCLSUBBATCH	     "render/openclsubbatch"
#define RANDOMCOUNT			 "render/randomcount"

#define FINALEARLYCLIP       "finalrender/earlyclip"
#define FINALYAXISUP         "finalrender/finalyaxisup"
#define FINALTRANSPARENCY    "finalrender/transparency"
#define FINALOPENCL          "finalrender/opencl"
#define FINALDOUBLEPRECISION "finalrender/dp64"
#define FINALSAVEXML		 "finalrender/savexml"
#define FINALDOALL		     "finalrender/doall"
#define FINALDOSEQUENCE	     "finalrender/dosequence"
#define FINALKEEPASPECT		 "finalrender/keepaspect"
#define FINALSCALE			 "finalrender/scale"
#define FINALEXT			 "finalrender/ext"
#define FINALDEVICES		 "finalrender/devices"
#define FINALTHREADCOUNT     "finalrender/threadcount"
#define FINALTHREADPRIORITY  "finalrender/threadpriority"
#define FINALQUALITY	     "finalrender/quality"
#define FINALTEMPORALSAMPLES "finalrender/temporalsamples"
#define FINALSUPERSAMPLE     "finalrender/supersample"
#define FINALSTRIPS		     "finalrender/strips"

#define XMLWIDTH			 "xml/width"
#define XMLHEIGHT			 "xml/height"
#define XMLTEMPORALSAMPLES	 "xml/temporalsamples"
#define XMLQUALITY			 "xml/quality"
#define XMLSUPERSAMPLE		 "xml/supersample"

#define OPENFOLDER			 "path/open"
#define SAVEFOLDER			 "path/save"

#define OPENXMLEXT			 "file/openxmlext"
#define SAVEXMLEXT			 "file/savexmlext"
#define OPENIMAGEEXT		 "file/openimageext"
#define SAVEIMAGEEXT		 "file/saveimageext"
#define AUTOUNIQUE			 "file/autounique"

#define IDENTITYID			 "identity/id"
#define IDENTITYURL			 "identity/url"
#define IDENTITYNICK		 "identity/nick"

#define UIVARIATIONS		 "ui/variations"

#define STYLETHEME			 "style/theme"

/// <summary>
/// Class for preserving various program options between
/// runs of Fractorium. Each of these generally corresponds
/// to items in the options dialog and the final render dialog.
/// </summary>
class FractoriumSettings : public QSettings
{
	Q_OBJECT
public:
	FractoriumSettings(QObject* p);
	void EnsureDefaults();

	bool EarlyClip();
	void EarlyClip(bool b);
	
	bool YAxisUp();
	void YAxisUp(bool b);

	bool Transparency();
	void Transparency(bool b);
	
	bool OpenCL();
	void OpenCL(bool b);
		
	bool Double();
	void Double(bool b);

	bool ShowAllXforms();
	void ShowAllXforms(bool b);

	bool ContinuousUpdate();
	void ContinuousUpdate(bool b);

	QList<QVariant> Devices();
	void Devices(const QList<QVariant>& devices);

	uint ThreadCount();
	void ThreadCount(uint i);

	bool CpuDEFilter();
	void CpuDEFilter(bool b);

	bool OpenCLDEFilter();
	void OpenCLDEFilter(bool b);

	uint CpuSubBatch();
	void CpuSubBatch(uint i);

	uint OpenCLSubBatch();
	void OpenCLSubBatch(uint i);
	
	uint RandomCount();
	void RandomCount(uint i);

	bool FinalEarlyClip();
	void FinalEarlyClip(bool b);
	
	bool FinalYAxisUp();
	void FinalYAxisUp(bool b);

	bool FinalTransparency();
	void FinalTransparency(bool b);

	bool FinalOpenCL();
	void FinalOpenCL(bool b);

	bool FinalDouble();
	void FinalDouble(bool b);
	
	bool FinalSaveXml();
	void FinalSaveXml(bool b);

	bool FinalDoAll();
	void FinalDoAll(bool b);

	bool FinalDoSequence();
	void FinalDoSequence(bool b);

	bool FinalKeepAspect();
	void FinalKeepAspect(bool b);
	
	uint FinalScale();
	void FinalScale(uint i);
	
	QString FinalExt();
	void FinalExt(const QString& s);

	QList<QVariant> FinalDevices();
	void FinalDevices(const QList<QVariant>& devices);

	uint FinalThreadCount();
	void FinalThreadCount(uint i);

	int FinalThreadPriority();
	void FinalThreadPriority(int b);

	uint FinalQuality();
	void FinalQuality(uint i);

	uint FinalTemporalSamples();
	void FinalTemporalSamples(uint i);

	uint FinalSupersample();
	void FinalSupersample(uint i);

	uint FinalStrips();
	void FinalStrips(uint i);

	uint XmlTemporalSamples();
	void XmlTemporalSamples(uint i);

	uint XmlQuality();
	void XmlQuality(uint i);

	uint XmlSupersample();
	void XmlSupersample(uint i);

	QString OpenFolder();
	void OpenFolder(const QString& s);

	QString SaveFolder();
	void SaveFolder(const QString& s);

	QString OpenXmlExt();
	void OpenXmlExt(const QString& s);

	QString SaveXmlExt();
	void SaveXmlExt(const QString& s);

	QString OpenImageExt();
	void OpenImageExt(const QString& s);

	QString SaveImageExt();
	void SaveImageExt(const QString& s);

	bool SaveAutoUnique();
	void SaveAutoUnique(bool b);

	QString Id();
	void Id(const QString& s);

	QString Url();
	void Url(const QString& s);

	QString Nick();
	void Nick(const QString& s);

	QMap<QString, QVariant> Variations();
	void Variations(const QMap<QString, QVariant>& m);

	QString Theme();
	void Theme(const QString& s);
};
