/* -*- c++ -*- */
/*
 * Copyright 2023 namalsanjaya.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "multDivSelect_impl.h"

namespace gr {
namespace customModule {
  using input_type = float;
  using output_type = float;
    multDivSelect::sptr
    multDivSelect::make()
    {
      return gnuradio::get_initial_sptr
        (new multDivSelect_impl());
    }


    /*
     * The private constructor
     */
    multDivSelect_impl::multDivSelect_impl(bool selector)
      : gr::sync_block("multDivSelect",
              gr::io_signature::make(2, 2, sizeof(input_type)),
              gr::io_signature::make(1, 1, sizeof(output_type)))
    {
       _selector = selector;
    }

    /*
     * Our virtual destructor.
     */
    multDivSelect_impl::~multDivSelect_impl()
    {
    }

    int
    multDivSelect_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      // const <+ITYPE+> *in = (const <+ITYPE+> *) input_items[0];
      // <+OTYPE+> *out = (<+OTYPE+> *) output_items[0];

      auto in0 = static_cast<const input_type*>(input_items[0]);
      auto in1 = static_cast<const input_type*>(input_items[1]);
      auto out = static_cast<output_type*>(output_items[0]);
      
      for (int index = 0; index < noutput_items; index++) {
        if (_selector) { out[index] = in0[index] * in1[index]; }
        else{ out[index] = in0[index] / in1[index]; }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace customModule */
} /* namespace gr */

