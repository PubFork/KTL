#pragma once

#include <boost/smart_ptr/shared_ptr.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/krkr/tjs.hpp>

#include "VariateRandomCommon.hpp"

namespace ktl {
	//
	// NativeVariateRandom
	//
	class NativeVariateRandom {
	public:
		typedef RandomUtils::variate_generator_type variate_generator_type;
		typedef RandomUtils::engine_variant_type engine_variant_type;
		typedef RandomUtils::distribution_variant_type distribution_variant_type;
	private:
		sprig::krkr::tjs::object_type engine_;
		sprig::krkr::tjs::object_type distribution_;
		variate_generator_type generator_;
	public:
		NativeVariateRandom();
		explicit NativeVariateRandom(iTJSDispatch2* eng_obj);
		NativeVariateRandom(iTJSDispatch2* eng_obj, iTJSDispatch2* dis_obj);
	public:
		//
		//	SUMMARY: �擾�n���\�b�h
		//
		RandomResult random();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		sprig::krkr::tjs::object_type engine() const;
		sprig::krkr::tjs::object_type distribution() const;
		//
		//	SUMMARY: �擾�v���p�e�B�n���\�b�h
		//
		RandomResult min() const;
		RandomResult max() const;
	};

	//
	// VariateRandom
	//
	class VariateRandom
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativeVariateRandom> instance_;
	public:
		VariateRandom();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
	public:
		//
		//	SUMMARY: �擾�n���\�b�h
		//
		tTJSVariant random();
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		tTJSVariant engine() const;
		tTJSVariant distribution() const;
		//
		//	SUMMARY: �擾�v���p�e�B�n���\�b�h
		//
		tTJSVariant min() const;
		tTJSVariant max() const;
	};
}	// namespace ktl
