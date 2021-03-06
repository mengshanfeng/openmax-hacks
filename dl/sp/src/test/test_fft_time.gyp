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
    # Include KissFFT.  Default is no. (Not available for arm64.)
    'kissfft%' : 0,
    # Include NE10 FFTs.  Default is no.
    'ne10%' : 0,
    # Include FFMPEG FFTs.  Default is no. (Not available for arm64.)
    'ffmpeg%' : 0,
    # Include CKFFT. Default is no.
    'ckfft%' : 0,
    # Include PFFFT. Default is no.
    'pffft%' : 0,
    # Inline asm for Ne10 on arm64.
    'ne10_arm64_inline_asm' : 0,
  },
  'target_defaults': {
    'include_dirs': [
      '../../../../',
    ],
    'dependencies' : [
      '../../../dl.gyp:openmax_dl',
      'test_utilities'
    ],
    'conditions': [
      ['target_arch == "arm64"', {
        'defines': [
          'FLOAT_ONLY',
        ],
      }],
      ['big_float_fft == 1', {
        'defines': [
          'BIG_FFT_TABLE',
        ],
      }],
      ['kissfft == 1 and target_arch == "arm"', {
        'defines': [
          'HAVE_KISSFFT',
        ],
        'dependencies' : [
          '../../../../third_party/other-fft/kissfft.gyp:kissfft',
        ],
      }],
      ['ne10 == 1', {
        'defines': [
          'HAVE_NE10',
        ],
        'dependencies' : [
          '../../../../third_party/other-fft/ne10.gyp:ne10',
        ]
      }],
      ['ffmpeg == 1 and target_arch == "arm"', {
        'defines': [
          'HAVE_FFMPEG',
        ],
        'dependencies' : [
          '../../../../third_party/other-fft/ffmpeg.gyp:ffmpeg',
        ]
      }],
      ['ckfft == 1', {
        'defines': [
          'HAVE_CKFFT',
        ],
        'dependencies' : [
          '../../../../third_party/other-fft/ckfft.gyp:ckfft'
        ],
      }],
      ['pffft == 1', {
        'defines': [
          'HAVE_PFFFT',
        ],
        'conditions': [
          ['target_arch == "arm"', {
            # fft_time_pffft.c needs Neon
            'cflags!': [
              '-mfpu=vfpv3-d16',
            ],
            'cflags': [
              # We enable Neon instructions even with arm_neon==0, to support
              # runtime detection.
              '-mfpu=neon',
            ],
          }],
        ],
        'dependencies' : [
          '../../../../third_party/other-fft/pffft.gyp:pffft'
        ],
      }],
    ],
  },
  'targets': [
    {
      # Test utilities
      'target_name': 'test_utilities',
      'type' : '<(component)',
      'dependencies!' : [
        'test_utilities'
      ],
      'sources' : [
        'aligned_ptr.c',
        'compare.c',
        'gensig.c',
        'test_util.c',
      ],
    },
    {
      # Simple timing test of FFTs
      'target_name': 'test_fft_time',
      'type': 'executable',
      'sources': [
        'test_fft_time.c',
        'fft_time_openmax.c',
      ],
      'conditions': [
        ['kissfft == 1', {
          'sources' : [
            'fft_time_kissfft.c',
            'fft_time_kissfft.h',
          ],
        }],
        ['ne10 == 1', {
          'sources' : [
            'fft_time_ne10.c',
            'fft_time_ne10.h',
          ],
        }],
        ['ffmpeg == 1', {
          'sources' : [
            'fft_time_ffmpeg.c',
            'fft_time_ffmpeg.h',
          ],
        }],
        ['ckfft == 1', {
          'sources' : [
            'fft_time_ckfft.c',
            'fft_time_ckfft.h',
          ],
        }],
        ['pffft == 1', {
          'sources' : [
            'fft_time_pffft.c',
            'fft_time_pffft.h',
          ],
        }],
      ],
    },
    {
      # Build all test programs.
      'target_name': 'All',
      'type': 'none',
      'dependencies': [
        'test_fft_time',
      ],
    },
  ],
}
