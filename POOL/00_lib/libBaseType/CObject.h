#pragma once
#ifndef _OBJECT_SECTION_H_
#define _OBJECT_SECTION_H_

#include <iostream>
#include <unistd.h>

using namespace std;

namespace ACES{

	class CObject {
		public:
			// Constructor
			CObject() : m_cid{"void"} { cout << "I was born .." << endl; }
			CObject(CObject& rhs) : m_cid(rhs.m_cid) { cout << "I was copied .." << endl; } 
			virtual ~CObject() { cout << "I am dieing .." << endl; }

			// introduce myself
			virtual string const to_string() const { return m_cid; }

			// update myself
			void string_to(string cid) { m_cid = cid; }

			// output stream operator overiding
			friend ostream& operator<<(ostream& o, const CObject& obj) {
				return o << "I am " << obj.to_string();
			}

			// my genome
			virtual bool is_kind_of(string class_name) { return class_name=="CObject"; }

			// selector
			string const& get_cid() const { return m_cid; };
			// const뒤에 &를 붙이는 이유는 caller쪽에서 객체를 복사하지 않고 그대로 받겠다는 의미이다.

			// actions (interface)
//			virtual int do_update(int flag) = 0;
//			virtual int increate_status(int temp) = 0;

			// operator
			virtual bool operator == (CObject& rhs) const { return this == &rhs; }

		protected:
			string m_cid;
	};
}


#endif
