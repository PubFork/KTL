#pragma once

#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/performance_timer.hpp>

namespace ktl {
	//
	// NativePerformanceCounter
	//
	class NativePerformanceCounter {
	private:
		std::vector<sprig::performance_timer::value_type> performance_times_;
		sprig::performance_timer performance_timer_;
		sprig::performance_timer unit_performance_timer_;
		bool enable_;
	public:
		NativePerformanceCounter();
	public:
		//
		//	SUMMARY: �o�͌n���\�b�h
		//
		void begin();
		void end();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		bool getEnable() const;
		void setEnable(bool v);
	};

	//
	// PerformanceCounter
	//
	class PerformanceCounter
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativePerformanceCounter> instance_;
	public:
		PerformanceCounter();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		void begin();
		void end();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		bool getEnable() const;
		void setEnable(bool v);
	};
}	// namespace ktl
