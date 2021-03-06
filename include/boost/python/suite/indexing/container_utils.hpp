//  (C) Copyright Joel de Guzman 2003.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef PY_CONTAINER_UTILS_TDS20090919_HPP
# define PY_CONTAINER_UTILS_TDS20090919_HPP

# include <utility>
# include <boost/foreach.hpp>
# include <boost/python/object.hpp>
# include <boost/python/handle.hpp>
# include <boost/python/extract.hpp>
# include <boost/python/stl_iterator.hpp>

namespace boost { namespace python { namespace container_utils {
        
    template <typename Container>
    void
    extend_container(Container& container, object l)
    {
        typedef typename Container::value_type data_type;
        
	boost::python::stl_input_iterator<object> begin(l), end;

	while(begin != end)
	  {
            extract<data_type const&> x(*begin);
            //  try if elem is an exact data_type type
            if (x.check())
            {
                container.push_back(x());
            }
            else
            {
                //  try to convert elem to data_type type
                extract<data_type> x(*begin);
                if (x.check())
                {
                    container.push_back(x());
                }
                else
                {
                    PyErr_SetString(PyExc_TypeError, "Incompatible Data Type");
                    throw_error_already_set();
                }
            }
	    ++begin;
        }
    }

}}} // namespace boost::python::container_utils

#endif
