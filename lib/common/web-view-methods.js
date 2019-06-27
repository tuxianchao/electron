'use strict'

// Public-facing API methods.
exports.syncMethods = new Set([
  'getURL',
  'loadURL',
  'getTitle',
  'isLoading',
  'isLoadingMainFrame',
  'isWaitingForResponse',
  'stop',
  'reload',
  'reloadIgnoringCache',
  'canGoBack',
  'canGoForward',
  'canGoToOffset',
  'clearHistory',
  'goBack',
  'goForward',
  'goToIndex',
  'goToOffset',
  'isCrashed',
  'setUserAgent',
  'getUserAgent',
  'openDevTools',
  'closeDevTools',
  'isDevToolsOpened',
  'isDevToolsFocused',
  'inspectElement',
  'setAudioMuted',
  'isAudioMuted',
  'isCurrentlyAudible',
  'undo',
  'redo',
  'cut',
  'copy',
  'paste',
  'pasteAndMatchStyle',
  'delete',
  'selectAll',
  'unselect',
  'replace',
  'replaceMisspelling',
  'findInPage',
  'stopFindInPage',
  'downloadURL',
  'inspectSharedWorker',
  'inspectServiceWorker',
  'showDefinitionForSelection',
  'getZoomFactor',
  'getZoomLevel',
  'setZoomFactor',
  'setZoomLevel'
])

exports.asyncMethods = new Set([
  'send',
  'sendInputEvent',
  'print'
])

exports.promisifiedMethods = new Set([
  // JS wrappers from webFrameMethods:
  'insertCSS',
  'insertText',
  'removeInsertedCSS',
  'setLayoutZoomLevelLimits',
  'setVisualZoomLevelLimits',
  // Native methods that return Promise:
  'capturePage',
  'executeJavaScript',
  'printToPDF'
])
