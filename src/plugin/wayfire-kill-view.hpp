/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2022 Scott Moreau
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <wayfire/plugins/common/input-grab.hpp>
#include <wayfire/util.hpp>

class wf_kill_view
{
    wl_global *manager;

  public:
    wf::pointer_interaction_t *base;
    void set_base_ptr(wf::pointer_interaction_t *base);
    std::vector<wl_resource*> client_resources;
    void send_view_info();
    void send_cancel();
    void deactivate(uint32_t b);
    wf::wl_idle_call idle_set_cursor;
    std::map<wf::output_t*, std::unique_ptr<wf::input_grab_t>> input_grabs;
    void end_grab(uint32_t b);
    wf_kill_view();
    ~wf_kill_view();
};
