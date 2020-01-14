//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "OC_Lexique.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    E X T E R N    R O U T I N E S                                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    E X T E R N    F U N C T I O N S                                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N                                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

enum {logo_lexique_1_,
  logo_lexique_1_identifier,
  logo_lexique_1_integer,
  logo_lexique_1__22_string_22_,
  logo_lexique_1_comment,
  logo_lexique_1_PROGRAM,
  logo_lexique_1_ROUTINE,
  logo_lexique_1_BEGIN,
  logo_lexique_1_END,
  logo_lexique_1_FORWARD,
  logo_lexique_1_ROTATE,
  logo_lexique_1_PEN,
  logo_lexique_1_UP,
  logo_lexique_1_DOWN,
  logo_lexique_1_CALL,
  logo_lexique_1__2E_,
  logo_lexique_1__3B_
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        U N I C O D E    T E S T    F U N C T I O N S                                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     S C A N N E R    C L A S S                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@interface OC_Lexique_logo_lexique : OC_Lexique {
//--- Attributes
  @private NSMutableString * mLexicalAttribute_tokenString ;
  @private UInt32 mLexicalAttribute_uint32value ;

}

- (NSUInteger) terminalVocabularyCount ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleCount ;

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex ;

- (NSString *) indexingDirectory ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) isTemplateLexique ;

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;

@end

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

