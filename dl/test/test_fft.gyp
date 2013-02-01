#  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
#
#  Use of this source code is governed by a BSD-style license
#  that can be found in the LICENSE file in the root of the source
#  tree. An additional intellectual property rights grant can be found
#  in the file PATENTS.  All contributing project authors may
#  be found in the AUTHORS file in the root of the source tree.

{
  'variables' : {
    # Override this value to build with small float FFT tables
    'big_float_fft%' : 1,
  },
  'targets': [
    {
      # Test utilities
      'target_name': 'test_utilities',
      'type' : '<(component)',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        '../arm_fft.gyp:arm_fft',
      ],
      'sources' : [
        'aligned_ptr.c',
        'compare.c',
        'gensig.c',
        'test_util.c',
      ],
    },
    {
      # Test complex fixed-point 32-bit FFT
      'target_name': 'test_fft32',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        '../arm_fft.gyp:arm_fft',
        'test_utilities'
      ],
      'sources': [
        'test_fft32.c',
      ],
    },
    {
      # Test real 32-bit fixed-point FFT
      'target_name': 'test_rfft32',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        'test_utilities'
      ],
      'sources': [
        'test_rfft32.c',
      ],
    },
    {
      # Test real 16-bit fixed-point FFT
      'target_name': 'test_rfft16',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        'test_utilities'
      ],
      'sources': [
        'test_rfft16.c',
      ],
    },
    {
      # Test complex floating-point FFT
      'target_name': 'test_float_fft',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        'test_utilities'
      ],
      'sources': [
        'test_float_fft.c',
      ],
      'conditions': [
        ['big_float_fft == 1', {
          'defines': [
            'BIG_FFT_TABLE',
          ],
        }],
      ],
    },
    {
      # Test real floating-point FFT
      'target_name': 'test_float_rfft',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        'test_utilities'
      ],
      'sources': [
        'test_float_rfft.c',
      ],
      'conditions': [
        ['big_float_fft == 1', {
          'defines': [
            'BIG_FFT_TABLE',
          ],
        }],
      ],
    },
    {
      # Simple timing test of FFTs
      'target_name': 'test_fft_time',
      'type': 'executable',
      'include_dirs': [
        '..',
      ],
      'dependencies' : [
        'test_utilities'
      ],
      'sources': [
        'test_fft_time.c',
      ],
      'conditions': [
        ['big_float_fft == 1', {
          'defines': [
            'BIG_FFT_TABLE',
          ],
        }],
      ],
    },
    {
      # Build all test programs.
      'target_name': 'All',
      'type': 'none',
      'dependencies': [
        'test_fft32',
        'test_float_fft',
        'test_float_rfft',
        'test_rfft16',
        'test_rfft32',
        'test_fft_time',
      ],
    },
  ],
}
