#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/krkr/tjs.hpp>

namespace ktl {
	//
	// NativeCppInt
	//
	class NativeCppInt {
	public:
		typedef boost::multiprecision::cpp_int big_int_type;
	private:
		big_int_type value_;
	public:
		static big_int_type convertValue(tTJSVariant const& v);
		static big_int_type convertValue(tTJSVariant const& v, int sign);
		static big_int_type convertValuePtr(tTJSVariant const* v);
		static sprig::krkr::tjs::intptr_type getInstance(iTJSDispatch2* obj);
		static sprig::krkr::tjs::object_type createNew(tjs_int numparams, tTJSVariant** param);
	public:
		NativeCppInt();
		explicit NativeCppInt(big_int_type const& value);
		explicit NativeCppInt(tTJSVariant const& v);
		NativeCppInt(tTJSVariant const& v, int sign);
		void reset(big_int_type const& value);
		big_int_type const& get() const;
		big_int_type& ref();
	public:
		//
		//	SUMMARY: ���Z�n���\�b�h
		//
		static sprig::krkr::tjs::object_type opAdd(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opSub(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opMul(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opDiv(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opMod(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opOr(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opAnd(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opXor(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: ����n���\�b�h
		//
		static bool opEq(tjs_int numparams, tTJSVariant** param);
		static bool opNEq(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: ��r�n���\�b�h
		//
		static bool opLs(tjs_int numparams, tTJSVariant** param);
		static bool opLsEq(tjs_int numparams, tTJSVariant** param);
		static bool opGr(tjs_int numparams, tTJSVariant** param);
		static bool opGrEq(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: �P�����Z�n���\�b�h
		//
		static sprig::krkr::tjs::object_type opPlus(tTJSVariant const& v);
		static sprig::krkr::tjs::object_type opMinus(tTJSVariant const& v);
		//
		//	SUMMARY: �Z�p�n���\�b�h
		//
		static sprig::krkr::tjs::object_type abs(tTJSVariant const& v);
		static sprig::krkr::tjs::object_type pow(tTJSVariant const& v, int e);
		static sprig::krkr::tjs::object_type gcd(tTJSVariant const& v1, tTJSVariant const& v2);
		static sprig::krkr::tjs::object_type max(tTJSVariant const& v1, tTJSVariant const& v2);
		static sprig::krkr::tjs::object_type min(tTJSVariant const& v1, tTJSVariant const& v2);
	public:
		//
		//	SUMMARY: ����n���\�b�h
		//
		NativeCppInt& assign(tTJSVariant const& v);
		//
		//	SUMMARY: ���Z����n���\�b�h
		//
		NativeCppInt& assignAdd(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignSub(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignMul(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignDiv(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignMod(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignOr(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignAnd(tjs_int numparams, tTJSVariant** param);
		NativeCppInt& assignXor(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: �ϊ��n���\�b�h
		//
		tTVInteger asInt() const;
		tTVReal asReal() const;
		tTJSString asString() const;
		tTJSVariant asOctet() const;
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		int sign() const;
	};

	//
	// CppInt
	//
	class CppInt
		: public tTJSNativeInstance
	{
	public:
		typedef NativeCppInt::big_int_type big_int_type;
	private:
		boost::shared_ptr<NativeCppInt> instance_;
	public:
		CppInt();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
		void reset(big_int_type const& value);
		big_int_type const& get() const;
		big_int_type& ref();
	public:
		//
		//	SUMMARY: ���Z�n���\�b�h
		//
		static sprig::krkr::tjs::object_type opAdd(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opSub(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opMul(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opDiv(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opMod(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opOr(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opAnd(tjs_int numparams, tTJSVariant** param);
		static sprig::krkr::tjs::object_type opXor(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: ����n���\�b�h
		//
		static bool opEq(tjs_int numparams, tTJSVariant** param);
		static bool opNEq(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: ��r�n���\�b�h
		//
		static bool opLs(tjs_int numparams, tTJSVariant** param);
		static bool opLsEq(tjs_int numparams, tTJSVariant** param);
		static bool opGr(tjs_int numparams, tTJSVariant** param);
		static bool opGrEq(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: �P�����Z�n���\�b�h
		//
		static sprig::krkr::tjs::object_type opPlus(tTJSVariant const& v);
		static sprig::krkr::tjs::object_type opMinus(tTJSVariant const& v);
		//
		//	SUMMARY: �Z�p�n���\�b�h
		//
		static sprig::krkr::tjs::object_type abs(tTJSVariant const& v);
		static sprig::krkr::tjs::object_type pow(tTJSVariant const& v, tTVInteger e);
		static sprig::krkr::tjs::object_type gcd(tTJSVariant const& v1, tTJSVariant const& v2);
		static sprig::krkr::tjs::object_type max(tTJSVariant const& v1, tTJSVariant const& v2);
		static sprig::krkr::tjs::object_type min(tTJSVariant const& v1, tTJSVariant const& v2);
	public:
		//
		//	SUMMARY: �����n���\�b�h
		//
		sprig::krkr::tjs::intptr_type getInstance();
		//
		//	SUMMARY: ����n���\�b�h
		//
		CppInt& assign(tTJSVariant const& v);
		//
		//	SUMMARY: ���Z����n���\�b�h
		//
		CppInt& assignAdd(tjs_int numparams, tTJSVariant** param);
		CppInt& assignSub(tjs_int numparams, tTJSVariant** param);
		CppInt& assignMul(tjs_int numparams, tTJSVariant** param);
		CppInt& assignDiv(tjs_int numparams, tTJSVariant** param);
		CppInt& assignMod(tjs_int numparams, tTJSVariant** param);
		CppInt& assignOr(tjs_int numparams, tTJSVariant** param);
		CppInt& assignAnd(tjs_int numparams, tTJSVariant** param);
		CppInt& assignXor(tjs_int numparams, tTJSVariant** param);
		//
		//	SUMMARY: �ϊ��n���\�b�h
		//
		tTVInteger asInt() const;
		tTVReal asReal() const;
		tTJSString asString() const;
		tTJSVariant asOctet() const;
		//
		//	SUMMARY: �v���p�e�B�n���\�b�h
		//
		tTVInteger sign() const;
	};
}	// namespace ktl
