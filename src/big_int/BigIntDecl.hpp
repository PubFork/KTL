#pragma once

#include <boost/smart_ptr/shared_ptr.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/serialization/sprig/ntl/big_int.hpp>
#include <sprig/krkr/tjs.hpp>

namespace ktl {
	//
	// NativeBigInt
	//
	class NativeBigInt {
	private:
		sprig::big_int value_;
	public:
		static sprig::big_int convertValue(tTJSVariant const& v);
		static sprig::big_int convertValue(tTJSVariant const& v, int sign);
		static sprig::big_int convertValuePtr(tTJSVariant const* v);
		static sprig::krkr::tjs::intptr_type getInstance(iTJSDispatch2* obj);
		static sprig::krkr::tjs::object_type createNew(tjs_int numparams, tTJSVariant** param);
	public:
		NativeBigInt();
		explicit NativeBigInt(sprig::big_int const& value);
		explicit NativeBigInt(tTJSVariant const& v);
		NativeBigInt(tTJSVariant const& v, int sign);
		void reset(sprig::big_int const& value);
		sprig::big_int const& get() const;
		sprig::big_int& ref();
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
		NativeBigInt& assign(tTJSVariant const& v);
		//
		//	SUMMARY: ���Z����n���\�b�h
		//
		NativeBigInt& assignAdd(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignSub(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignMul(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignDiv(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignMod(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignOr(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignAnd(tjs_int numparams, tTJSVariant** param);
		NativeBigInt& assignXor(tjs_int numparams, tTJSVariant** param);
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
	// BigInt
	//
	class BigInt
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativeBigInt> instance_;
	public:
		BigInt();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
		void reset(sprig::big_int const& value);
		sprig::big_int const& get() const;
		sprig::big_int& ref();
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
		BigInt& assign(tTJSVariant const& v);
		//
		//	SUMMARY: ���Z����n���\�b�h
		//
		BigInt& assignAdd(tjs_int numparams, tTJSVariant** param);
		BigInt& assignSub(tjs_int numparams, tTJSVariant** param);
		BigInt& assignMul(tjs_int numparams, tTJSVariant** param);
		BigInt& assignDiv(tjs_int numparams, tTJSVariant** param);
		BigInt& assignMod(tjs_int numparams, tTJSVariant** param);
		BigInt& assignOr(tjs_int numparams, tTJSVariant** param);
		BigInt& assignAnd(tjs_int numparams, tTJSVariant** param);
		BigInt& assignXor(tjs_int numparams, tTJSVariant** param);
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
