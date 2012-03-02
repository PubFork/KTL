#pragma once

#include <boost/smart_ptr/shared_ptr.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/krkr/tjs.hpp>

#include "ThreadTaskCommon.hpp"

namespace ktl {
	//
	// NativeThreadTask
	//
	class NativeThreadTask {
	private:
		boost::shared_ptr<ThreadTaskImpl> impl_;
	public:
		NativeThreadTask();
	public:
		//
		//	SUMMARY: ����n���\�b�h
		//
		bool start(tTJSVariantClosure const& closure);
		bool cancel();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		tTJSVariant result() const;
		bool isProcessing() const;
		bool cancelled() const;
	};
	//
	// NativeThreadControl
	//
	class NativeThreadControl {
	public:
		typedef ThreadTaskImpl::time_count_type time_count_type;
	private:
		boost::shared_ptr<ThreadTaskImpl> impl_;
	public:
		NativeThreadControl();
		void initImpl(boost::shared_ptr<ThreadTaskImpl> const& impl);
	public:
		//
		//	SUMMARY: ����n���\�b�h
		//
		void yield();
		void sleep(time_count_type milliseconds);
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		bool cancelled() const;
	};

	//
	// ThreadTask
	//
	class ThreadTask
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativeThreadTask> instance_;
	public:
		ThreadTask();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
	public:
		//
		//	SUMMARY: ����n���\�b�h
		//
		bool start(tTJSVariantClosure const& closure);
		bool cancel();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		tTJSVariant result() const;
		bool isProcessing() const;
		bool cancelled() const;
	};
	//
	// ThreadControl
	//
	class ThreadControl
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativeThreadControl> instance_;
	public:
		ThreadControl();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
		void initImpl(boost::shared_ptr<ThreadTaskImpl> const& impl);
	public:
		//
		//	SUMMARY: �����n���\�b�h
		//
		sprig::krkr::tjs::intptr_type getInstance();
		//
		//	SUMMARY: ����n���\�b�h
		//
		void yield();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		bool cancelled() const;
		void sleep(tTVInteger milliseconds);
	};
}	// namespace ktl
