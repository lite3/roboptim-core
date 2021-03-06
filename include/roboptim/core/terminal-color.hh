// Copyright (C) 2013 by Thomas Moulard, AIST, CNRS, INRIA.
//
// This file is part of the roboptim.
//
// roboptim is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// roboptim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with roboptim.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROBOPTIM_CORE_TERMINAL_COLOR_HH
# define ROBOPTIM_CORE_TERMINAL_COLOR_HH
# include <roboptim/core/debug.hh>

# include <iostream>

# ifndef _WIN32
#  include <cstdio>
#  include <unistd.h>
# endif // _WIN32

# ifdef _WIN32
#  define ROBOPTIM_CORE_FILTER_TTY()			\
  do							\
    {							\
      return o;						\
    }							\
  while (0)
# else
#  define ROBOPTIM_CORE_FILTER_TTY()			\
  do							\
    {							\
      if (o == std::cout && !isatty (fileno (stdout)))	\
	return o;					\
      if (o == std::cerr && !isatty (fileno (stderr)))	\
	return o;					\
      if (o != std::cout && o != std::cerr)		\
	return o;					\
    }							\
  while (0)
#endif // _WIN32


namespace roboptim
{
  namespace fg
  {
    inline std::ostream& reset (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[m";
      return o;
    }

    inline std::ostream& red (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[0;31m";
      return o;
    }

    inline std::ostream& green (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[0;32m";
      return o;
    }

    inline std::ostream& yellow (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[0;33m";
      return o;
    }

    inline std::ostream& blue (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[0;34m";
      return o;
    }

    inline std::ostream& orange (std::ostream& o)
    {
      ROBOPTIM_CORE_FILTER_TTY ();
      o << "\033[33;40m";
      return o;
    }


    inline std::ostream& ok (std::ostream& o)
    {
      o << green;
      return o;
    }

    inline std::ostream& fail (std::ostream& o)
    {
      o << red;
      return o;
    }

    inline std::ostream& warn (std::ostream& o)
    {
      o << orange;
      return o;
    }

  } // end of namespace fg.
}

#endif // !MISC_INDENT_HH
