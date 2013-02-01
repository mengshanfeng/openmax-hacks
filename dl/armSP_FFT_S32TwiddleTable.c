/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 *
 *  This file was originally licensed as follows. It has been
 *  relicensed with permission from the copyright holders.
 */

/**
 * 
 * File Name:  armSP_FFT_S32TwiddleTable.c
 * OpenMAX DL: v1.0.2
 * Last Modified Revision:   6781
 * Last Modified Date:       Wed, 25 Jul 2007
 * 
 * (c) Copyright 2007-2008 ARM Limited. All Rights Reserved.
 * 
 * 
 *
 * Description:
 * Twiddle table for Forward FFT in Q31 format.
 * It contains complex pairs [-cos (W * i), -sin (W * i)] where W = -2*PI/N
 * and 0<= i<= N/8.  N is the max size of the FFT. Here N = 2^12.
 * Values for N/8 < i < N are generated in the FFTInit function using the 
 * symmetries of cos and sine.
 * 
 * NOTE: The values are stored negated. This is to represent '1' which cannot be otherwise 
 * represented as Q31 in 32 bits. 
**/

#include "omxtypes.h"


const OMX_S32 armSP_FFT_S32TwiddleTable[1026] ={

0x80000000,		0x0,
0x800009df,		0x3243f5,
0x8000277a,		0x6487e3,
0x800058d4,		0x96cbc1,
0x80009dea,		0xc90f88,
0x8000f6bd,		0xfb5330,
0x8001634e,		0x12d96b1,
0x8001e39b,		0x15fda03,
0x800277a6,		0x1921d20,
0x80031f6d,		0x1c45ffe,
0x8003daf1,		0x1f6a297,
0x8004aa32,		0x228e4e2,
0x80058d2f,		0x25b26d7,
0x800683e8,		0x28d6870,
0x80078e5e,		0x2bfa9a4,
0x8008ac90,		0x2f1ea6c,
0x8009de7e,		0x3242abf,
0x800b2427,		0x3566a96,
0x800c7d8c,		0x388a9ea,
0x800deaad,		0x3bae8b2,
0x800f6b88,		0x3ed26e6,
0x8011001f,		0x41f6480,
0x8012a86f,		0x451a177,
0x8014647b,		0x483ddc3,
0x80163440,		0x4b6195d,
0x801817bf,		0x4e8543e,
0x801a0ef8,		0x51a8e5c,
0x801c19ea,		0x54cc7b1,
0x801e3895,		0x57f0035,
0x80206af8,		0x5b137df,
0x8022b114,		0x5e36ea9,
0x80250ae7,		0x615a48b,
0x80277872,		0x647d97c,
0x8029f9b4,		0x67a0d76,
0x802c8ead,		0x6ac406f,
0x802f375d,		0x6de7262,
0x8031f3c2,		0x710a345,
0x8034c3dd,		0x742d311,
0x8037a7ac,		0x77501be,
0x803a9f31,		0x7a72f45,
0x803daa6a,		0x7d95b9e,
0x8040c956,		0x80b86c2,
0x8043fbf6,		0x83db0a7,
0x80474248,		0x86fd947,
0x804a9c4d,		0x8a2009a,
0x804e0a04,		0x8d42699,
0x80518b6b,		0x9064b3a,
0x80552084,		0x9386e78,
0x8058c94c,		0x96a9049,
0x805c85c4,		0x99cb0a7,
0x806055eb,		0x9cecf89,
0x806439c0,		0xa00ece8,
0x80683143,		0xa3308bd,
0x806c3c74,		0xa6522fe,
0x80705b50,		0xa973ba5,
0x80748dd9,		0xac952aa,
0x8078d40d,		0xafb6805,
0x807d2dec,		0xb2d7baf,
0x80819b74,		0xb5f8d9f,
0x80861ca6,		0xb919dcf,
0x808ab180,		0xbc3ac35,
0x808f5a02,		0xbf5b8cb,
0x8094162c,		0xc27c389,
0x8098e5fb,		0xc59cc68,
0x809dc971,		0xc8bd35e,
0x80a2c08b,		0xcbdd865,
0x80a7cb49,		0xcefdb76,
0x80ace9ab,		0xd21dc87,
0x80b21baf,		0xd53db92,
0x80b76156,		0xd85d88f,
0x80bcba9d,		0xdb7d376,
0x80c22784,		0xde9cc40,
0x80c7a80a,		0xe1bc2e4,
0x80cd3c2f,		0xe4db75b,
0x80d2e3f2,		0xe7fa99e,
0x80d89f51,		0xeb199a4,
0x80de6e4c,		0xee38766,
0x80e450e2,		0xf1572dc,
0x80ea4712,		0xf475bff,
0x80f050db,		0xf7942c7,
0x80f66e3c,		0xfab272b,
0x80fc9f35,		0xfdd0926,
0x8102e3c4,		0x100ee8ad,
0x81093be8,		0x1040c5bb,
0x810fa7a0,		0x1072a048,
0x811626ec,		0x10a4784b,
0x811cb9ca,		0x10d64dbd,
0x8123603a,		0x11082096,
0x812a1a3a,		0x1139f0cf,
0x8130e7c9,		0x116bbe60,
0x8137c8e6,		0x119d8941,
0x813ebd90,		0x11cf516a,
0x8145c5c7,		0x120116d5,
0x814ce188,		0x1232d979,
0x815410d4,		0x1264994e,
0x815b53a8,		0x1296564d,
0x8162aa04,		0x12c8106f,
0x816a13e6,		0x12f9c7aa,
0x8171914e,		0x132b7bf9,
0x8179223a,		0x135d2d53,
0x8180c6a9,		0x138edbb1,
0x81887e9a,		0x13c0870a,
0x81904a0c,		0x13f22f58,
0x819828fd,		0x1423d492,
0x81a01b6d,		0x145576b1,
0x81a82159,		0x148715ae,
0x81b03ac2,		0x14b8b17f,
0x81b867a5,		0x14ea4a1f,
0x81c0a801,		0x151bdf86,
0x81c8fbd6,		0x154d71aa,
0x81d16321,		0x157f0086,
0x81d9dde1,		0x15b08c12,
0x81e26c16,		0x15e21445,
0x81eb0dbe,		0x16139918,
0x81f3c2d7,		0x16451a83,
0x81fc8b60,		0x1676987f,
0x82056758,		0x16a81305,
0x820e56be,		0x16d98a0c,
0x82175990,		0x170afd8d,
0x82206fcc,		0x173c6d80,
0x82299971,		0x176dd9de,
0x8232d67f,		0x179f429f,
0x823c26f3,		0x17d0a7bc,
0x82458acc,		0x1802092c,
0x824f0208,		0x183366e9,
0x82588ca7,		0x1864c0ea,
0x82622aa6,		0x18961728,
0x826bdc04,		0x18c7699b,
0x8275a0c0,		0x18f8b83c,
0x827f78d8,		0x192a0304,
0x8289644b,		0x195b49ea,
0x82936317,		0x198c8ce7,
0x829d753a,		0x19bdcbf3,
0x82a79ab3,		0x19ef0707,
0x82b1d381,		0x1a203e1b,
0x82bc1fa2,		0x1a517128,
0x82c67f14,		0x1a82a026,
0x82d0f1d5,		0x1ab3cb0d,
0x82db77e5,		0x1ae4f1d6,
0x82e61141,		0x1b161479,
0x82f0bde8,		0x1b4732ef,
0x82fb7dd8,		0x1b784d30,
0x83065110,		0x1ba96335,
0x8311378d,		0x1bda74f6,
0x831c314e,		0x1c0b826a,
0x83273e52,		0x1c3c8b8c,
0x83325e97,		0x1c6d9053,
0x833d921b,		0x1c9e90b8,
0x8348d8dc,		0x1ccf8cb3,
0x835432d8,		0x1d00843d,
0x835fa00f,		0x1d31774d,
0x836b207d,		0x1d6265dd,
0x8376b422,		0x1d934fe5,
0x83825afb,		0x1dc4355e,
0x838e1507,		0x1df5163f,
0x8399e244,		0x1e25f282,
0x83a5c2b0,		0x1e56ca1e,
0x83b1b649,		0x1e879d0d,
0x83bdbd0e,		0x1eb86b46,
0x83c9d6fc,		0x1ee934c3,
0x83d60412,		0x1f19f97b,
0x83e2444d,		0x1f4ab968,
0x83ee97ad,		0x1f7b7481,
0x83fafe2e,		0x1fac2abf,
0x840777d0,		0x1fdcdc1b,
0x84140490,		0x200d888d,
0x8420a46c,		0x203e300d,
0x842d5762,		0x206ed295,
0x843a1d70,		0x209f701c,
0x8446f695,		0x20d0089c,
0x8453e2cf,		0x21009c0c,
0x8460e21a,		0x21312a65,
0x846df477,		0x2161b3a0,
0x847b19e1,		0x219237b5,
0x84885258,		0x21c2b69c,
0x84959dd9,		0x21f3304f,
0x84a2fc62,		0x2223a4c5,
0x84b06df2,		0x225413f8,
0x84bdf286,		0x22847de0,
0x84cb8a1b,		0x22b4e274,
0x84d934b1,		0x22e541af,
0x84e6f244,		0x23159b88,
0x84f4c2d4,		0x2345eff8,
0x8502a65c,		0x23763ef7,
0x85109cdd,		0x23a6887f,
0x851ea652,		0x23d6cc87,
0x852cc2bb,		0x24070b08,
0x853af214,		0x243743fa,
0x8549345c,		0x24677758,
0x85578991,		0x2497a517,
0x8565f1b0,		0x24c7cd33,
0x85746cb8,		0x24f7efa2,
0x8582faa5,		0x25280c5e,
0x85919b76,		0x2558235f,
0x85a04f28,		0x2588349d,
0x85af15b9,		0x25b84012,
0x85bdef28,		0x25e845b6,
0x85ccdb70,		0x26184581,
0x85dbda91,		0x26483f6c,
0x85eaec88,		0x26783370,
0x85fa1153,		0x26a82186,
0x860948ef,		0x26d809a5,
0x86189359,		0x2707ebc7,
0x8627f091,		0x2737c7e3,
0x86376092,		0x27679df4,
0x8646e35c,		0x27976df1,
0x865678eb,		0x27c737d3,
0x8666213c,		0x27f6fb92,
0x8675dc4f,		0x2826b928,
0x8685aa20,		0x2856708d,
0x86958aac,		0x288621b9,
0x86a57df2,		0x28b5cca5,
0x86b583ee,		0x28e5714b,
0x86c59c9f,		0x29150fa1,
0x86d5c802,		0x2944a7a2,
0x86e60614,		0x29743946,
0x86f656d3,		0x29a3c485,
0x8706ba3d,		0x29d34958,
0x8717304e,		0x2a02c7b8,
0x8727b905,		0x2a323f9e,
0x8738545e,		0x2a61b101,
0x87490258,		0x2a911bdc,
0x8759c2ef,		0x2ac08026,
0x876a9621,		0x2aefddd8,
0x877b7bec,		0x2b1f34eb,
0x878c744d,		0x2b4e8558,
0x879d7f41,		0x2b7dcf17,
0x87ae9cc5,		0x2bad1221,
0x87bfccd7,		0x2bdc4e6f,
0x87d10f75,		0x2c0b83fa,
0x87e2649b,		0x2c3ab2b9,
0x87f3cc48,		0x2c69daa6,
0x88054677,		0x2c98fbba,
0x8816d327,		0x2cc815ee,
0x88287256,		0x2cf72939,
0x883a23ff,		0x2d263596,
0x884be821,		0x2d553afc,
0x885dbeb8,		0x2d843964,
0x886fa7c2,		0x2db330c7,
0x8881a33d,		0x2de2211e,
0x8893b125,		0x2e110a62,
0x88a5d177,		0x2e3fec8b,
0x88b80432,		0x2e6ec792,
0x88ca4951,		0x2e9d9b70,
0x88dca0d3,		0x2ecc681e,
0x88ef0ab4,		0x2efb2d95,
0x890186f2,		0x2f29ebcc,
0x89141589,		0x2f58a2be,
0x8926b677,		0x2f875262,
0x893969b9,		0x2fb5fab2,
0x894c2f4c,		0x2fe49ba7,
0x895f072e,		0x30133539,
0x8971f15a,		0x3041c761,
0x8984edcf,		0x30705217,
0x8997fc8a,		0x309ed556,
0x89ab1d87,		0x30cd5115,
0x89be50c3,		0x30fbc54d,
0x89d1963c,		0x312a31f8,
0x89e4edef,		0x3158970e,
0x89f857d8,		0x3186f487,
0x8a0bd3f5,		0x31b54a5e,
0x8a1f6243,		0x31e39889,
0x8a3302be,		0x3211df04,
0x8a46b564,		0x32401dc6,
0x8a5a7a31,		0x326e54c7,
0x8a6e5123,		0x329c8402,
0x8a823a36,		0x32caab6f,
0x8a963567,		0x32f8cb07,
0x8aaa42b4,		0x3326e2c3,
0x8abe6219,		0x3354f29b,
0x8ad29394,		0x3382fa88,
0x8ae6d720,		0x33b0fa84,
0x8afb2cbb,		0x33def287,
0x8b0f9462,		0x340ce28b,
0x8b240e11,		0x343aca87,
0x8b3899c6,		0x3468aa76,
0x8b4d377c,		0x34968250,
0x8b61e733,		0x34c4520d,
0x8b76a8e4,		0x34f219a8,
0x8b8b7c8f,		0x351fd918,
0x8ba0622f,		0x354d9057,
0x8bb559c1,		0x357b3f5d,
0x8bca6343,		0x35a8e625,
0x8bdf7eb0,		0x35d684a6,
0x8bf4ac05,		0x36041ad9,
0x8c09eb40,		0x3631a8b8,
0x8c1f3c5d,		0x365f2e3b,
0x8c349f58,		0x368cab5c,
0x8c4a142f,		0x36ba2014,
0x8c5f9ade,		0x36e78c5b,
0x8c753362,		0x3714f02a,
0x8c8addb7,		0x37424b7b,
0x8ca099da,		0x376f9e46,
0x8cb667c8,		0x379ce885,
0x8ccc477d,		0x37ca2a30,
0x8ce238f6,		0x37f76341,
0x8cf83c30,		0x382493b0,
0x8d0e5127,		0x3851bb77,
0x8d2477d8,		0x387eda8e,
0x8d3ab03f,		0x38abf0ef,
0x8d50fa59,		0x38d8fe93,
0x8d675623,		0x39060373,
0x8d7dc399,		0x3932ff87,
0x8d9442b8,		0x395ff2c9,
0x8daad37b,		0x398cdd32,
0x8dc175e0,		0x39b9bebc,
0x8dd829e4,		0x39e6975e,
0x8deeef82,		0x3a136712,
0x8e05c6b7,		0x3a402dd2,
0x8e1caf80,		0x3a6ceb96,
0x8e33a9da,		0x3a99a057,
0x8e4ab5bf,		0x3ac64c0f,
0x8e61d32e,		0x3af2eeb7,
0x8e790222,		0x3b1f8848,
0x8e904298,		0x3b4c18ba,
0x8ea7948c,		0x3b78a007,
0x8ebef7fb,		0x3ba51e29,
0x8ed66ce1,		0x3bd19318,
0x8eedf33b,		0x3bfdfecd,
0x8f058b04,		0x3c2a6142,
0x8f1d343a,		0x3c56ba70,
0x8f34eed8,		0x3c830a50,
0x8f4cbadb,		0x3caf50da,
0x8f649840,		0x3cdb8e09,
0x8f7c8701,		0x3d07c1d6,
0x8f94871d,		0x3d33ec39,
0x8fac988f,		0x3d600d2c,
0x8fc4bb53,		0x3d8c24a8,
0x8fdcef66,		0x3db832a6,
0x8ff534c4,		0x3de4371f,
0x900d8b69,		0x3e10320d,
0x9025f352,		0x3e3c2369,
0x903e6c7b,		0x3e680b2c,
0x9056f6df,		0x3e93e950,
0x906f927c,		0x3ebfbdcd,
0x90883f4d,		0x3eeb889c,
0x90a0fd4e,		0x3f1749b8,
0x90b9cc7d,		0x3f430119,
0x90d2acd4,		0x3f6eaeb8,
0x90eb9e50,		0x3f9a5290,
0x9104a0ee,		0x3fc5ec98,
0x911db4a9,		0x3ff17cca,
0x9136d97d,		0x401d0321,
0x91500f67,		0x40487f94,
0x91695663,		0x4073f21d,
0x9182ae6d,		0x409f5ab6,
0x919c1781,		0x40cab958,
0x91b5919a,		0x40f60dfb,
0x91cf1cb6,		0x4121589b,
0x91e8b8d0,		0x414c992f,
0x920265e4,		0x4177cfb1,
0x921c23ef,		0x41a2fc1a,
0x9235f2ec,		0x41ce1e65,
0x924fd2d7,		0x41f93689,
0x9269c3ac,		0x42244481,
0x9283c568,		0x424f4845,
0x929dd806,		0x427a41d0,
0x92b7fb82,		0x42a5311b,
0x92d22fd9,		0x42d0161e,
0x92ec7505,		0x42faf0d4,
0x9306cb04,		0x4325c135,
0x932131d1,		0x4350873c,
0x933ba968,		0x437b42e1,
0x935631c5,		0x43a5f41e,
0x9370cae4,		0x43d09aed,
0x938b74c1,		0x43fb3746,
0x93a62f57,		0x4425c923,
0x93c0faa3,		0x4450507e,
0x93dbd6a0,		0x447acd50,
0x93f6c34a,		0x44a53f93,
0x9411c09e,		0x44cfa740,
0x942cce96,		0x44fa0450,
0x9447ed2f,		0x452456bd,
0x94631c65,		0x454e9e80,
0x947e5c33,		0x4578db93,
0x9499ac95,		0x45a30df0,
0x94b50d87,		0x45cd358f,
0x94d07f05,		0x45f7526b,
0x94ec010b,		0x4621647d,
0x95079394,		0x464b6bbe,
0x9523369c,		0x46756828,
0x953eea1e,		0x469f59b4,
0x955aae17,		0x46c9405c,
0x95768283,		0x46f31c1a,
0x9592675c,		0x471cece7,
0x95ae5c9f,		0x4746b2bc,
0x95ca6247,		0x47706d93,
0x95e67850,		0x479a1d67,
0x96029eb6,		0x47c3c22f,
0x961ed574,		0x47ed5be6,
0x963b1c86,		0x4816ea86,
0x965773e7,		0x48406e08,
0x9673db94,		0x4869e665,
0x96905388,		0x48935397,
0x96acdbbe,		0x48bcb599,
0x96c97432,		0x48e60c62,
0x96e61ce0,		0x490f57ee,
0x9702d5c3,		0x49389836,
0x971f9ed7,		0x4961cd33,
0x973c7817,		0x498af6df,
0x9759617f,		0x49b41533,
0x97765b0a,		0x49dd282a,
0x979364b5,		0x4a062fbd,
0x97b07e7a,		0x4a2f2be6,
0x97cda855,		0x4a581c9e,
0x97eae242,		0x4a8101de,
0x98082c3b,		0x4aa9dba2,
0x9825863d,		0x4ad2a9e2,
0x9842f043,		0x4afb6c98,
0x98606a49,		0x4b2423be,
0x987df449,		0x4b4ccf4d,
0x989b8e40,		0x4b756f40,
0x98b93828,		0x4b9e0390,
0x98d6f1fe,		0x4bc68c36,
0x98f4bbbc,		0x4bef092d,
0x9912955f,		0x4c177a6e,
0x99307ee0,		0x4c3fdff4,
0x994e783d,		0x4c6839b7,
0x996c816f,		0x4c9087b1,
0x998a9a74,		0x4cb8c9dd,
0x99a8c345,		0x4ce10034,
0x99c6fbde,		0x4d092ab0,
0x99e5443b,		0x4d31494b,
0x9a039c57,		0x4d595bfe,
0x9a22042d,		0x4d8162c4,
0x9a407bb9,		0x4da95d96,
0x9a5f02f5,		0x4dd14c6e,
0x9a7d99de,		0x4df92f46,
0x9a9c406e,		0x4e210617,
0x9abaf6a1,		0x4e48d0dd,
0x9ad9bc71,		0x4e708f8f,
0x9af891db,		0x4e984229,
0x9b1776da,		0x4ebfe8a5,
0x9b366b68,		0x4ee782fb,
0x9b556f81,		0x4f0f1126,
0x9b748320,		0x4f369320,
0x9b93a641,		0x4f5e08e3,
0x9bb2d8de,		0x4f857269,
0x9bd21af3,		0x4faccfab,
0x9bf16c7a,		0x4fd420a4,
0x9c10cd70,		0x4ffb654d,
0x9c303dcf,		0x50229da1,
0x9c4fbd93,		0x5049c999,
0x9c6f4cb6,		0x5070e92f,
0x9c8eeb34,		0x5097fc5e,
0x9cae9907,		0x50bf031f,
0x9cce562c,		0x50e5fd6d,
0x9cee229c,		0x510ceb40,
0x9d0dfe54,		0x5133cc94,
0x9d2de94d,		0x515aa162,
0x9d4de385,		0x518169a5,
0x9d6decf4,		0x51a82555,
0x9d8e0597,		0x51ced46e,
0x9dae2d68,		0x51f576ea,
0x9dce6463,		0x521c0cc2,
0x9deeaa82,		0x524295f0,
0x9e0effc1,		0x5269126e,
0x9e2f641b,		0x528f8238,
0x9e4fd78a,		0x52b5e546,
0x9e705a09,		0x52dc3b92,
0x9e90eb94,		0x53028518,
0x9eb18c26,		0x5328c1d0,
0x9ed23bb9,		0x534ef1b5,
0x9ef2fa49,		0x537514c2,
0x9f13c7d0,		0x539b2af0,
0x9f34a449,		0x53c13439,
0x9f558fb0,		0x53e73097,
0x9f7689ff,		0x540d2005,
0x9f979331,		0x5433027d,
0x9fb8ab41,		0x5458d7f9,
0x9fd9d22a,		0x547ea073,
0x9ffb07e7,		0x54a45be6,
0xa01c4c73,		0x54ca0a4b,
0xa03d9fc8,		0x54efab9c,
0xa05f01e1,		0x55153fd4,
0xa08072ba,		0x553ac6ee,
0xa0a1f24d,		0x556040e2,
0xa0c38095,		0x5585adad,
0xa0e51d8c,		0x55ab0d46,
0xa106c92f,		0x55d05faa,
0xa1288376,		0x55f5a4d2,
0xa14a4c5e,		0x561adcb9,
0xa16c23e1,		0x56400758,
0xa18e09fa,		0x566524aa,
0xa1affea3,		0x568a34a9,
0xa1d201d7,		0x56af3750,
0xa1f41392,		0x56d42c99,
0xa21633cd,		0x56f9147e,
0xa2386284,		0x571deefa,
0xa25a9fb1,		0x5742bc06,
0xa27ceb4f,		0x57677b9d,
0xa29f4559,		0x578c2dba,
0xa2c1adc9,		0x57b0d256,
0xa2e4249b,		0x57d5696d,
0xa306a9c8,		0x57f9f2f8,
0xa3293d4b,		0x581e6ef1,
0xa34bdf20,		0x5842dd54,
0xa36e8f41,		0x58673e1b,
0xa3914da8,		0x588b9140,
0xa3b41a50,		0x58afd6bd,
0xa3d6f534,		0x58d40e8c,
0xa3f9de4e,		0x58f838a9,
0xa41cd599,		0x591c550e,
0xa43fdb10,		0x594063b5,
0xa462eeac,		0x59646498,
0xa486106a,		0x598857b2,
0xa4a94043,		0x59ac3cfd,
0xa4cc7e32,		0x59d01475,
0xa4efca31,		0x59f3de12,
0xa513243b,		0x5a1799d1,
0xa5368c4b,		0x5a3b47ab,
0xa55a025b,		0x5a5ee79a,
0xa57d8666,		0x5a82799a
};

/*End of File*/
