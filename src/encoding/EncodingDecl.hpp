#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <sprig/external/unicode/ucsdet.hpp>
#include <sprig/external/tp_stub.hpp>
#include <sprig/krkr/tjs.hpp>

namespace ktl {
	//
	// NativeEncoding
	//
	class NativeEncoding {
	public:
		typedef boost::uint_fast32_t flag_type;
		typedef boost::int_fast32_t int_type;
		typedef std::vector<tjs_uint8> binary_type;
		typedef std::basic_string<tjs_char> string_type;
		typedef std::size_t size_type;
	private:
		static bool encodeAsBuffer(
			binary_type& buffer,
			tjs_char const* to,
			tjs_char const* source
			);
		static bool encodeAsBuffer(
			binary_type& buffer,
			tjs_char const* to,
			tjs_uint8 const* source_data,
			tjs_uint source_length,
			tjs_char const* from
			);
		static bool encodeAsString(
			string_type& string,
			tjs_uint8 const* source_data,
			tjs_uint source_length,
			tjs_char const* from
			);
		static bool URLEncodeAsBuffer(
			binary_type& dest,
			binary_type const& src,
			flag_type flag = 0x00000000
			);
		static bool URLDecodeAsBuffer(
			binary_type& dest,
			binary_type const& src
			);
		static bool base64EncodeAsBuffer(
			binary_type& dest,
			tjs_uint8 const* source_data,
			tjs_uint source_length,
			size_type line_max_length = 76
			);
		static bool base64DecodeAsBuffer(
			binary_type& dest,
			tjs_char const* source
			);
		static bool base64DecodeAsBuffer(
			binary_type& dest,
			tjs_uint8 const* source_data,
			tjs_uint source_length
			);
		static boost::shared_ptr<UCharsetDetector> setupDetector(
			tjs_uint8 const* source_data,
			tjs_uint source_length
			);
		static tTJSVariant makeMatchResult(
			UCharsetMatch const* matcher,
			int_type confidence_threshold
			);
	public:
		NativeEncoding();
	public:
		//
		//	SUMMARY: URL�G���R�[�h�n�t���O
		//
		static flag_type const uefSpaceToPlus = 0x00000001;
		static flag_type const uefEncodeTilde = 0x00000100;
	public:
		//
		//	SUMMARY: URL�G���R�[�h�n���\�b�h
		//
		static tTJSVariant URLEncodeToOctet(
			tjs_char const* to,
			tjs_char const* source,
			flag_type flag = 0x00000000
			);
		static tTJSVariant URLEncodeToOctet(
			tjs_char const* to,
			tTJSVariantOctet const* source,
			tjs_char const* from,
			flag_type flag = 0x00000000
			);
		static tTJSVariant URLEncodeToString(
			tjs_char const* to,
			tjs_char const* source,
			flag_type flag = 0x00000000
			);
		static tTJSVariant URLEncodeToString(
			tjs_char const* to,
			tTJSVariantOctet const* source,
			tjs_char const* from,
			flag_type flag = 0x00000000
			);
		static tTJSVariant URLDecodeToOctet(
			tjs_char const* to,
			tjs_char const* source
			);
		static tTJSVariant URLDecodeToOctet(
			tjs_char const* to,
			tTJSVariantOctet const* source,
			tjs_char const* from
			);
		static tTJSVariant URLDecodeToString(
			tjs_char const* to,
			tjs_char const* source
			);
		static tTJSVariant URLDecodeToString(
			tjs_char const* to,
			tTJSVariantOctet const* source,
			tjs_char const* from
			);
		//
		//	SUMMARY: Base64�G���R�[�h�n���\�b�h
		//
		static tTJSVariant base64EncodeToOctet(
			tTJSVariantOctet const* source,
			size_type line_max_length = 76
			);
		static tTJSVariant base64EncodeToString(
			tTJSVariantOctet const* source,
			size_type line_max_length = 76
			);
		static tTJSVariant base64DecodeToOctet(
			tjs_char const* source
			);
		static tTJSVariant base64DecodeToOctet(
			tTJSVariantOctet const* source
			);
		//
		//	SUMMARY: �G���R�[�h�n���\�b�h
		//
		static tTJSVariant encodeToOctet(
			tjs_char const* to,
			tjs_char const* source
			);
		static tTJSVariant encodeToOctet(
			tjs_char const* to,
			tTJSVariantOctet const* source,
			tjs_char const* from
			);
		static tTJSVariant encodeToString(
			tTJSVariantOctet const* source,
			tjs_char const* from
			);
		//
		//	SUMMARY: ��r�n���\�b�h
		//
		static bool sameCharsetAlias(
			tjs_char const* name1,
			tjs_char const* name2
			);
		//
		//	SUMMARY: ���o�n���\�b�h
		//
		static tTJSVariant detect(
			tTJSVariantOctet const* source,
			size_type length = 0,
			int_type confidence_threshold = 0
			);
		static tTJSVariant detectAll(
			tTJSVariantOctet const* source,
			size_type length = 0,
			int_type confidence_threshold = 0
			);
		static bool checkDetected(
			tjs_char const* charset_name,
			tTJSVariantOctet const* source,
			size_type length = 0,
			int_type confidence_threshold = 0
			);
	};

	//
	// Encoding
	//
	class Encoding
		: public tTJSNativeInstance
	{
	private:
		boost::shared_ptr<NativeEncoding> instance_;
	public:
		Encoding();
		tjs_error TJS_INTF_METHOD Construct(
			tjs_int numparams,
			tTJSVariant** param,
			iTJSDispatch2* tjs_obj
			);
		void TJS_INTF_METHOD Invalidate();
	public:
		//
		//	SUMMARY: URL�G���R�[�h�n�t���O
		//
		static tTVInteger const uefSpaceToPlus = NativeEncoding::uefSpaceToPlus;
		static tTVInteger const uefEncodeTilde = NativeEncoding::uefEncodeTilde;
	public:
		//
		//	SUMMARY: URL�G���R�[�h�n���\�b�h
		//
		static tTJSVariant URLEncodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantString const* source,
			tTVInteger flag = 0x00000000
			);
		static tTJSVariant URLEncodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantOctet const* source,
			tTJSVariantString const* from,
			tTVInteger flag = 0x00000000
			);
		static tTJSVariant URLEncodeToString(
			tTJSVariantString const* to,
			tTJSVariantString const* source,
			tTVInteger flag = 0x00000000
			);
		static tTJSVariant URLEncodeToString(
			tTJSVariantString const* to,
			tTJSVariantOctet const* source,
			tTJSVariantString const* from,
			tTVInteger flag = 0x00000000
			);
		static tTJSVariant URLDecodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantString const* source
			);
		static tTJSVariant URLDecodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantOctet const* source,
			tTJSVariantString const* from
			);
		static tTJSVariant URLDecodeToString(
			tTJSVariantString const* to,
			tTJSVariantString const* source
			);
		static tTJSVariant URLDecodeToString(
			tTJSVariantString const* to,
			tTJSVariantOctet const* source,
			tTJSVariantString const* from
			);
		//
		//	SUMMARY: Base64�G���R�[�h�n���\�b�h
		//
		static tTJSVariant base64EncodeToOctet(
			tTJSVariantOctet const* source,
			tTVInteger line_max_length = 76
			);
		static tTJSVariant base64EncodeToString(
			tTJSVariantOctet const* source,
			tTVInteger line_max_length = 76
			);
		static tTJSVariant base64DecodeToOctet(
			tTJSVariantString const* source
			);
		static tTJSVariant base64DecodeToOctet(
			tTJSVariantOctet const* source
			);
		//
		//	SUMMARY: �G���R�[�h�n���\�b�h
		//
		static tTJSVariant encodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantString const* source
			);
		static tTJSVariant encodeToOctet(
			tTJSVariantString const* to,
			tTJSVariantOctet const* source,
			tTJSVariantString const* from
			);
		static tTJSVariant encodeToString(
			tTJSVariantOctet const* source,
			tTJSVariantString const* from
			);
		//
		//	SUMMARY: ��r�n���\�b�h
		//
		static bool sameCharsetAlias(
			tTJSVariantString const* name1,
			tTJSVariantString const* name2
			);
		//
		//	SUMMARY: ���o�n���\�b�h
		//
		static tTJSVariant detect(
			tTJSVariantOctet const* source,
			tTVInteger length = 0,
			tTVInteger confidence_threshold = 0
			);
		static tTJSVariant detectAll(
			tTJSVariantOctet const* source,
			tTVInteger length = 0,
			tTVInteger confidence_threshold = 0
			);
		static bool checkDetected(
			tTJSVariantString const* charset_name,
			tTJSVariantOctet const* source,
			tTVInteger length = 0,
			tTVInteger confidence_threshold = 0
			);
	};
}	// namespace ktl
