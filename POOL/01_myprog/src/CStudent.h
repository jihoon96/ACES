#pragma once
#include "../../00_lib/libBaseType/CObject.h"

using namespace ACES;

class CStudent : public CObject {
	public:
		// birth
		CStudent(string id, string name) : m_id(id), m_name(name) { string_to(name); }
		CStudent(CStudent& rhs) : m_id(rhs.m_id), m_name(rhs.m_name) { string_to(rhs.get_name()); }

		// introduce my self
		virtual string const to_string() const;

		// selector
		string const& get_id() const { return m_id; }
		string const& get_name() const { return m_name; }

		// my genome
		virtual bool is_kind_of(string class_name) { return class_name=="CStudent"; }
		// actions (interface)
		virtual int do_update(int flag){ return 1; }
		virtual int increate_status(int temp){ return 1; }

		// operator
		virtual bool operator == (CStudent& rhs) const { return m_id == ((CStudent*)&rhs)->get_id(); }


	protected:
		string m_id;
		string m_name;

};
