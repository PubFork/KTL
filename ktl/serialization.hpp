/*=============================================================================
  Copyright (c) 2010-2014 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/KTL

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef KTL_SERIALIZATION_HPP
#define KTL_SERIALIZATION_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <ktl/config.hpp>

#include <sprig/external/tp_stub.hpp>

namespace ktl {
	//
	// ISerializer
	//
	class ISerializer {
	public:
		typedef tTJSString key_type;
		typedef tTVInteger version_type;
	public:
		virtual ~ISerializer() {}
		virtual void save(
			tTJSVariant* result,
			tjs_int numparams,
			tTJSVariant** param
			) const
			= 0;
		virtual void load(
			tTJSVariant* result,
			tjs_int numparams,
			tTJSVariant** param
			) const
			= 0;
		virtual version_type version() const = 0;
		virtual key_type identity() const = 0;
	};

	//
	// ISerializationStack
	//
	class ISerializationStack {
	public:
		typedef ISerializer::key_type key_type;
		typedef ISerializer::version_type version_type;
	public:
		virtual ~ISerializationStack() {}
		//	SUMMARY: �v�f�̒l�̐ݒ�����݂�
		//		: �V���A���C�U�̌ďo���K�v�łȂ��Ȃ�΁A�^��Ԃ�
		//		: �V���A���C�U�̌ďo���K�v�ł���Ȃ�΁A�U��Ԃ�
		//		: �V���A���C�Y���ɌĂ΂��
		virtual bool set(
			key_type const& key,
			tTJSVariant const* v,
			key_type const* ser	/* optional */
			)
			= 0;

		//	SUMMARY: �V�����X�^�b�N��ς�
		//		: �V���A���C�Y���ɌĂ΂��
		virtual void pushOnSave(
			key_type const& key,
			tTJSVariant const* v,
			key_type const& ser,
			version_type const ver,
			key_type const& identity
			)
			= 0;

		//	SUMMARY: �X�^�b�N��߂�
		//		: �V���A���C�Y���ɌĂ΂��
		virtual void popOnSave() = 0;

		//	SUMMARY: �V���A���C�U�̌ďo���K�v���ǂ���
		//		: �K�v�łȂ��Ȃ�΁A�^��Ԃ�
		//		: �K�v�ł���Ȃ�΁A�U��Ԃ�
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual bool isLeaf(key_type const& key) = 0;

		//	SUMMARY: �v�f�̒l�𒼐ڎ擾����
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual void get(key_type const& key, tTJSVariant* v) = 0;

		//	SUMMARY: �����̃X�^�b�N��ς�
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual void pushOnLoad(key_type const& key) = 0;

		//	SUMMARY: �X�^�b�N��߂�
		//		: �V���A���C�U���Ԃ����C���X�^���X��o�^����
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual void popOnLoad(tTJSVariant const* v) = 0;

		//	SUMMARY: ���݂̃X�^�b�N����A�v�f�̃V���A���C�U�L�[��Ԃ�
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual key_type serializer(key_type const& key) = 0;

		//	SUMMARY: ���݂̃X�^�b�N����A�v�f�̃V���A���C�U�o�[�W������Ԃ�
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual version_type version(key_type const& key) = 0;

		//	SUMMARY: ���݂̃X�^�b�N����A�v�f�̃V���A���C�UID��Ԃ�
		//		: �f�V���A���C�Y���ɌĂ΂��
		virtual key_type identity(key_type const& key) = 0;
	};
}	// namespace ktl

#endif	// #ifndef KTL_SERIALIZATION_HPP
