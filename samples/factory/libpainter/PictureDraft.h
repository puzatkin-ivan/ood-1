#pragma once
#include <memory>
#include <vector>
#include <boost/iterator/indirect_iterator.hpp>
#include "Shape.h"


class CPictureDraft
{

public:
	typedef std::vector<std::unique_ptr<CShape>> Storage;


	CPictureDraft();

	bool IsEmpty()const;

	typedef boost::indirect_iterator<Storage::const_iterator, Storage::value_type> ConstIterator;

	ConstIterator begin()const;

	ConstIterator end()const;

	void AddShape(std::unique_ptr<CShape> && shape);

	CPictureDraft(CPictureDraft &&) = default;
	CPictureDraft& operator=(CPictureDraft &&) = default;

	CPictureDraft(const CPictureDraft &) = delete;
	CPictureDraft& operator=(const CPictureDraft &) = delete;
private:
	Storage m_shapes;
};
