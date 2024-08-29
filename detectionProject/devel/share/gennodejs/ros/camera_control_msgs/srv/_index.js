
"use strict";

let GetCamProperties = require('./GetCamProperties.js')
let SetSleeping = require('./SetSleeping.js')
let SetBinning = require('./SetBinning.js')
let SetGain = require('./SetGain.js')
let SetBrightness = require('./SetBrightness.js')
let SetBool = require('./SetBool.js')
let SetGamma = require('./SetGamma.js')
let SetROI = require('./SetROI.js')
let SetExposure = require('./SetExposure.js')

module.exports = {
  GetCamProperties: GetCamProperties,
  SetSleeping: SetSleeping,
  SetBinning: SetBinning,
  SetGain: SetGain,
  SetBrightness: SetBrightness,
  SetBool: SetBool,
  SetGamma: SetGamma,
  SetROI: SetROI,
  SetExposure: SetExposure,
};
