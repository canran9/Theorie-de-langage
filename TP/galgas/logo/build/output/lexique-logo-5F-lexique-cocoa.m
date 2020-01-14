//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-logo-5F-lexique-cocoa.h"
#import "PMDebug.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//            Unicode test functions                                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
 
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@implementation OC_Lexique_logo_lexique

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Template Replacements                                                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Template Delimiters                                                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_uint32value = 0 ;
  }
  return self ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSString *) indexingDirectory {
  return @"" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 I N D E X I N G    T I T L E S                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSArray *) indexingTitles { // Array of NSString

  return [NSArray array] ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//            Terminal Symbols as end of script in template mark                                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Key words table 'keyWordList'                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const C_cocoa_lexique_table_entry ktable_for_logo_5F_lexique_keyWordList [10] = {
  {"UP", logo_lexique_1_UP},
  {"END", logo_lexique_1_END},
  {"PEN", logo_lexique_1_PEN},
  {"CALL", logo_lexique_1_CALL},
  {"DOWN", logo_lexique_1_DOWN},
  {"BEGIN", logo_lexique_1_BEGIN},
  {"ROTATE", logo_lexique_1_ROTATE},
  {"FORWARD", logo_lexique_1_FORWARD},
  {"PROGRAM", logo_lexique_1_PROGRAM},
  {"ROUTINE", logo_lexique_1_ROUTINE}
} ;

static NSInteger search_into_logo_5F_lexique_keyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_logo_5F_lexique_keyWordList, 10) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               P A R S E    L E X I C A L    T O K E N                                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenStartLocation = mCurrentLocation ;
    [mLexicalAttribute_tokenString setString:@""] ;
    mLexicalAttribute_uint32value = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (mTokenCode == 0) {
        mTokenCode = search_into_logo_5F_lexique_keyWordList (mLexicalAttribute_tokenString) ;
      }
      if (mTokenCode == 0) {
        mTokenCode = logo_lexique_1_identifier ;
      }
    }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      scanner_cocoa_routine_convertDecimalStringIntoUInt (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_uint32value) ;
      mTokenCode = logo_lexique_1_integer ;
    }else if (scanningOk && ([self testForInputChar:34])) {
      do {
        if (scanningOk && ([self testForInputChar:32] || [self testForInputChar:33] || [self testForInputFromChar:35 toChar:65533])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputChar:34])) {
        mTokenCode = logo_lexique_1__22_string_22_ ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
      mTokenCode = logo_lexique_1__3B_ ;
    }else if (scanningOk && [self testForInputString:@"." advance:YES]) {
      mTokenCode = logo_lexique_1__2E_ ;
    }else if (scanningOk && ([self testForInputChar:35])) {
      do {
        if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = logo_lexique_1_comment ;
    }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
    }else if ([self testForInputChar:'\0']) { // End of source text ? 
      mTokenCode = logo_lexique_1_ ; // Empty string code
    }else{ // Unknown input character
      scanningOk = NO ;
      [self advance] ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   T E R M I N A L    C O U N T                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSUInteger) terminalVocabularyCount {
  return 16 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     S T Y L E   C O U N T                                                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSUInteger) styleCount {
  return 6 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                I S    T E M P L A T E    L E X I Q U E                                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (BOOL) isTemplateLexique {
  return NO ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [17] = {0,
    0 /* logo_lexique_1_identifier */,
    2 /* logo_lexique_1_integer */,
    3 /* logo_lexique_1__22_string_22_ */,
    5 /* logo_lexique_1_comment */,
    1 /* logo_lexique_1_PROGRAM */,
    1 /* logo_lexique_1_ROUTINE */,
    1 /* logo_lexique_1_BEGIN */,
    1 /* logo_lexique_1_END */,
    1 /* logo_lexique_1_FORWARD */,
    1 /* logo_lexique_1_ROTATE */,
    1 /* logo_lexique_1_PEN */,
    1 /* logo_lexique_1_UP */,
    1 /* logo_lexique_1_DOWN */,
    1 /* logo_lexique_1_CALL */,
    4 /* logo_lexique_1__2E_ */,
    4 /* logo_lexique_1__3B_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [17] = {NO,
    YES /* logo_lexique_1_identifier */,
    YES /* logo_lexique_1_integer */,
    NO /* logo_lexique_1__22_string_22_ */,
    NO /* logo_lexique_1_comment */,
    YES /* logo_lexique_1_PROGRAM */,
    YES /* logo_lexique_1_ROUTINE */,
    YES /* logo_lexique_1_BEGIN */,
    YES /* logo_lexique_1_END */,
    YES /* logo_lexique_1_FORWARD */,
    YES /* logo_lexique_1_ROTATE */,
    YES /* logo_lexique_1_PEN */,
    YES /* logo_lexique_1_UP */,
    YES /* logo_lexique_1_DOWN */,
    YES /* logo_lexique_1_CALL */,
    YES /* logo_lexique_1__2E_ */,
    YES /* logo_lexique_1__3B_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             S T Y L E   N A M E    F O R    I N D E X                                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"Default Style",
      @"Keywords",
      @"Integer Constants",
      @"String Constants",
      @"Delimiters",
      @"Comments"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X                                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"logo_lexique",
      @"logo_lexique-keywordsStyle",
      @"logo_lexique-integerStyle",
      @"logo_lexique-stringStyle",
      @"logo_lexique-delimitersStyle",
      @"logo_lexique-commentStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         L E X I Q U E   I D E N T I F I E R                                                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

- (NSString *) lexiqueIdentifier {
  return @"logo_lexique" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


