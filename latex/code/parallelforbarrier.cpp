// Copyright (c) 2012-2020 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

myQueue.submit([&](handler & cgh) {
  cgh.parallel_for<class example_kernel>(
      nd_range<3>(range<3>(4, 4, 4), range<3>(2, 2, 2)), [=](nd_item<3> item) {
        //[kernel code]
        // Internal synchronization
        item.barrier(access::fence_space::global_space);
        //[kernel code]
      });
});
