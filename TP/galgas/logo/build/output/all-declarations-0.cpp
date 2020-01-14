#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-0.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cTokenFor_logo_5F_lexique::cTokenFor_logo_5F_lexique (void) :
mLexicalAttribute_tokenString (),
mLexicalAttribute_uint_33__32_value () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_Lexique_logo_5F_lexique::C_Lexique_logo_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceFileName
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_Lexique_logo_5F_lexique::C_Lexique_logo_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceString,
                                                      const C_String & inStringForError
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_logo_5F_lexique::indexingDirectory (void) const {
  return "" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                        Lexical error message list                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * gLexicalMessage_logo_5F_lexique_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_logo_5F_lexique_incorrectStringEnd = "string does not end with '\"'" ;

static const char * gLexicalMessage_logo_5F_lexique_internalError = "internal error" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//          Syntax error messages, for every terminal symbol                                                           *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_identifier = "an identifier" ;

//--- Syntax error message for terminal '$integer$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_integer = "a 32-bit unsigned decimal number" ;

//--- Syntax error message for terminal '$"string"$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique__22_string_22_ = "a character string constant \"...\"" ;

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_comment = "a comment" ;

//--- Syntax error message for terminal '$PROGRAM$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_PROGRAM = "the 'PROGRAM' keyword" ;

//--- Syntax error message for terminal '$ROUTINE$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_ROUTINE = "the 'ROUTINE' keyword" ;

//--- Syntax error message for terminal '$BEGIN$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_BEGIN = "the 'BEGIN' keyword" ;

//--- Syntax error message for terminal '$END$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_END = "the 'END' keyword" ;

//--- Syntax error message for terminal '$FORWARD$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_FORWARD = "the 'FORWARD' keyword" ;

//--- Syntax error message for terminal '$ROTATE$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_ROTATE = "the 'ROTATE' keyword" ;

//--- Syntax error message for terminal '$PEN$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_PEN = "the 'PEN' keyword" ;

//--- Syntax error message for terminal '$UP$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_UP = "the 'UP' keyword" ;

//--- Syntax error message for terminal '$DOWN$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_DOWN = "the 'DOWN' keyword" ;

//--- Syntax error message for terminal '$CALL$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique_CALL = "the 'CALL' keyword" ;

//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique__2E_ = "the '.' delimitor" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage_logo_5F_lexique__3B_ = "the ';' delimitor" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                getMessageForTerminal                                                                                *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_logo_5F_lexique::getMessageForTerminal (const int16_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 17)) {
    static const char * syntaxErrorMessageArray [17] = {kEndOfSourceLexicalErrorMessage,
        gSyntaxErrorMessage_logo_5F_lexique_identifier,
        gSyntaxErrorMessage_logo_5F_lexique_integer,
        gSyntaxErrorMessage_logo_5F_lexique__22_string_22_,
        gSyntaxErrorMessage_logo_5F_lexique_comment,
        gSyntaxErrorMessage_logo_5F_lexique_PROGRAM,
        gSyntaxErrorMessage_logo_5F_lexique_ROUTINE,
        gSyntaxErrorMessage_logo_5F_lexique_BEGIN,
        gSyntaxErrorMessage_logo_5F_lexique_END,
        gSyntaxErrorMessage_logo_5F_lexique_FORWARD,
        gSyntaxErrorMessage_logo_5F_lexique_ROTATE,
        gSyntaxErrorMessage_logo_5F_lexique_PEN,
        gSyntaxErrorMessage_logo_5F_lexique_UP,
        gSyntaxErrorMessage_logo_5F_lexique_DOWN,
        gSyntaxErrorMessage_logo_5F_lexique_CALL,
        gSyntaxErrorMessage_logo_5F_lexique__2E_,
        gSyntaxErrorMessage_logo_5F_lexique__3B_
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                      U N I C O D E    S T R I N G S                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//--- Unicode string for '$_2E_$'
static const utf32 kUnicodeString_logo_5F_lexique__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_logo_5F_lexique__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$BEGIN$'
static const utf32 kUnicodeString_logo_5F_lexique_BEGIN [] = {
  TO_UNICODE ('B'),
  TO_UNICODE ('E'),
  TO_UNICODE ('G'),
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$CALL$'
static const utf32 kUnicodeString_logo_5F_lexique_CALL [] = {
  TO_UNICODE ('C'),
  TO_UNICODE ('A'),
  TO_UNICODE ('L'),
  TO_UNICODE ('L'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$DOWN$'
static const utf32 kUnicodeString_logo_5F_lexique_DOWN [] = {
  TO_UNICODE ('D'),
  TO_UNICODE ('O'),
  TO_UNICODE ('W'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$END$'
static const utf32 kUnicodeString_logo_5F_lexique_END [] = {
  TO_UNICODE ('E'),
  TO_UNICODE ('N'),
  TO_UNICODE ('D'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$FORWARD$'
static const utf32 kUnicodeString_logo_5F_lexique_FORWARD [] = {
  TO_UNICODE ('F'),
  TO_UNICODE ('O'),
  TO_UNICODE ('R'),
  TO_UNICODE ('W'),
  TO_UNICODE ('A'),
  TO_UNICODE ('R'),
  TO_UNICODE ('D'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$PEN$'
static const utf32 kUnicodeString_logo_5F_lexique_PEN [] = {
  TO_UNICODE ('P'),
  TO_UNICODE ('E'),
  TO_UNICODE ('N'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$PROGRAM$'
static const utf32 kUnicodeString_logo_5F_lexique_PROGRAM [] = {
  TO_UNICODE ('P'),
  TO_UNICODE ('R'),
  TO_UNICODE ('O'),
  TO_UNICODE ('G'),
  TO_UNICODE ('R'),
  TO_UNICODE ('A'),
  TO_UNICODE ('M'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$ROTATE$'
static const utf32 kUnicodeString_logo_5F_lexique_ROTATE [] = {
  TO_UNICODE ('R'),
  TO_UNICODE ('O'),
  TO_UNICODE ('T'),
  TO_UNICODE ('A'),
  TO_UNICODE ('T'),
  TO_UNICODE ('E'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$ROUTINE$'
static const utf32 kUnicodeString_logo_5F_lexique_ROUTINE [] = {
  TO_UNICODE ('R'),
  TO_UNICODE ('O'),
  TO_UNICODE ('U'),
  TO_UNICODE ('T'),
  TO_UNICODE ('I'),
  TO_UNICODE ('N'),
  TO_UNICODE ('E'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$UP$'
static const utf32 kUnicodeString_logo_5F_lexique_UP [] = {
  TO_UNICODE ('U'),
  TO_UNICODE ('P'),
  TO_UNICODE (0)
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//             Key words table 'delimitorsList'                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const int32_t ktable_size_logo_5F_lexique_delimitorsList = 2 ;

static const C_unicode_lexique_table_entry ktable_for_logo_5F_lexique_delimitorsList [ktable_size_logo_5F_lexique_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique__2E_, 1, C_Lexique_logo_5F_lexique::kToken__2E_),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique__3B_, 1, C_Lexique_logo_5F_lexique::kToken__3B_)
} ;

int16_t C_Lexique_logo_5F_lexique::search_into_delimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_logo_5F_lexique_delimitorsList, ktable_size_logo_5F_lexique_delimitorsList) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//             Key words table 'keyWordList'                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const int32_t ktable_size_logo_5F_lexique_keyWordList = 10 ;

static const C_unicode_lexique_table_entry ktable_for_logo_5F_lexique_keyWordList [ktable_size_logo_5F_lexique_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_UP, 2, C_Lexique_logo_5F_lexique::kToken_UP),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_END, 3, C_Lexique_logo_5F_lexique::kToken_END),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_PEN, 3, C_Lexique_logo_5F_lexique::kToken_PEN),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_CALL, 4, C_Lexique_logo_5F_lexique::kToken_CALL),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_DOWN, 4, C_Lexique_logo_5F_lexique::kToken_DOWN),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_BEGIN, 5, C_Lexique_logo_5F_lexique::kToken_BEGIN),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_ROTATE, 6, C_Lexique_logo_5F_lexique::kToken_ROTATE),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_FORWARD, 7, C_Lexique_logo_5F_lexique::kToken_FORWARD),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_PROGRAM, 7, C_Lexique_logo_5F_lexique::kToken_PROGRAM),
  C_unicode_lexique_table_entry (kUnicodeString_logo_5F_lexique_ROUTINE, 7, C_Lexique_logo_5F_lexique::kToken_ROUTINE)
} ;

int16_t C_Lexique_logo_5F_lexique::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_logo_5F_lexique_keyWordList, ktable_size_logo_5F_lexique_keyWordList) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                          getCurrentTokenString                                                                      *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_logo_5F_lexique::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_logo_5F_lexique * ptr = (const cTokenFor_logo_5F_lexique *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_integer:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("integer") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_uint_33__32_value) ;
      break ;
    case kToken__22_string_22_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\"string\"") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_PROGRAM:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("PROGRAM") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_ROUTINE:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("ROUTINE") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_BEGIN:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("BEGIN") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_END:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("END") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_FORWARD:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("FORWARD") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_ROTATE:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("ROTATE") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_PEN:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("PEN") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_UP:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("UP") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_DOWN:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("DOWN") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_CALL:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("CALL") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                           Template Delimiters                                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                           Template Replacements                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//            Terminal Symbols as end of script in template mark                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//            Unicode test functions                                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
 
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool C_Lexique_logo_5F_lexique::parseLexicalToken (void) {
  cTokenFor_logo_5F_lexique token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_tokenString.setLengthToZero () ;
    token.mLexicalAttribute_uint_33__32_value = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    try{
      if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (token.mTokenCode == -1) {
          token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
        }
        if (token.mTokenCode == -1) {
          token.mTokenCode = kToken_identifier ;
        }
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        ::scanner_routine_convertDecimalStringIntoUInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_logo_5F_lexique_decimalNumberTooLarge, gLexicalMessage_logo_5F_lexique_internalError) ;
        token.mTokenCode = kToken_integer ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        do {
          if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
          token.mTokenCode = kToken__22_string_22_ ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_logo_5F_lexique_incorrectStringEnd COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_logo_5F_lexique__3B_, 1, true)) {
        token.mTokenCode = kToken__3B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_logo_5F_lexique__2E_, 1, true)) {
        token.mTokenCode = kToken__2E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        enterDroppedTerminal (kToken_comment) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
        token.mTokenCode = -1 ; // No token
        advance () ; // ... go throught unknown character
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                         E N T E R    T O K E N                                                                      *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_Lexique_logo_5F_lexique::enterToken (cTokenFor_logo_5F_lexique & ioToken) {
  cTokenFor_logo_5F_lexique * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_logo_5F_lexique ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  ptr->mLexicalAttribute_uint_33__32_value = ioToken.mLexicalAttribute_uint_33__32_value ;
  enterTokenFromPointer (ptr) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//               A T T R I B U T E   A C C E S S                                                                       *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_logo_5F_lexique::attributeValue_tokenString (void) const {
  cTokenFor_logo_5F_lexique * ptr = (cTokenFor_logo_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t C_Lexique_logo_5F_lexique::attributeValue_uint_33__32_value (void) const {
  cTokenFor_logo_5F_lexique * ptr = (cTokenFor_logo_5F_lexique *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_uint_33__32_value ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring C_Lexique_logo_5F_lexique::synthetizedAttribute_tokenString (void) const {
  cTokenFor_logo_5F_lexique * ptr = (cTokenFor_logo_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_logo_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_luint C_Lexique_logo_5F_lexique::synthetizedAttribute_uint_33__32_value (void) const {
  cTokenFor_logo_5F_lexique * ptr = (cTokenFor_logo_5F_lexique *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_logo_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_uint_33__32_value) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                         I N T R O S P E C T I O N                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringlist C_Lexique_logo_5F_lexique::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("integer") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\"string\"") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("PROGRAM") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("ROUTINE") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("BEGIN") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("END") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("FORWARD") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("ROTATE") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("PEN") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("UP") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("DOWN") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("CALL") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void getKeywordLists_logo_5F_lexique (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("logo_lexique:delimitorsList") ;
  ioList.appendObject ("logo_lexique:keyWordList") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void getKeywordsForIdentifier_logo_5F_lexique (const C_String & inIdentifier,
                                                      bool & ioFound,
                                                      TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "logo_lexique:delimitorsList") {
    ioFound = true ;
    ioList.appendObject (".") ;
    ioList.appendObject (";") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "logo_lexique:keyWordList") {
    ioFound = true ;
    ioList.appendObject ("UP") ;
    ioList.appendObject ("END") ;
    ioList.appendObject ("PEN") ;
    ioList.appendObject ("CALL") ;
    ioList.appendObject ("DOWN") ;
    ioList.appendObject ("BEGIN") ;
    ioList.appendObject ("ROTATE") ;
    ioList.appendObject ("FORWARD") ;
    ioList.appendObject ("PROGRAM") ;
    ioList.appendObject ("ROUTINE") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static cLexiqueIntrospection lexiqueIntrospection_logo_5F_lexique
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_logo_5F_lexique, getKeywordsForIdentifier_logo_5F_lexique) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t C_Lexique_logo_5F_lexique::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [17] = {0,
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
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_Lexique_logo_5F_lexique::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 6) {
    static const char * kStyleArray [6] = {
      "",
      "keywordsStyle",
      "integerStyle",
      "stringStyle",
      "delimitersStyle",
      "commentStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_routineMap::cMapElement_routineMap (const GALGAS_lstring & inKey
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cMapElement_routineMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cMapElement_routineMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_routineMap (mProperty_lkey COMMA_HERE)) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cMapElement_routineMap::description (C_String & /* ioString */, const int32_t /* inIndentation */) const {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cMapElement_routineMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_routineMap * operand = (cMapElement_routineMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap::GALGAS_routineMap (void) :
AC_GALGAS_map () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap::GALGAS_routineMap (const GALGAS_routineMap & inSource) :
AC_GALGAS_map (inSource) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap & GALGAS_routineMap::operator = (const GALGAS_routineMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap GALGAS_routineMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_routineMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap GALGAS_routineMap::constructor_mapWithMapToOverride (const GALGAS_routineMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_routineMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap GALGAS_routineMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_routineMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_routineMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_routineMap * p = NULL ;
  macroMyNew (p, cMapElement_routineMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@routineMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_routineMap::setter_insertKey (GALGAS_lstring inKey,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_routineMap * p = NULL ;
  macroMyNew (p, cMapElement_routineMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' routine has been already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * kSearchErrorMessage_routineMap_searchKey = "the '%K' routine is not declared" ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_routineMap::method_searchKey (GALGAS_lstring inKey,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_routineMap * p = (const cMapElement_routineMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_routineMap_searchKey
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
  }else{
    macroValidSharedObject (p, cMapElement_routineMap) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement_routineMap * GALGAS_routineMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_routineMap * result = (cMapElement_routineMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_routineMap) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cEnumerator_routineMap::cEnumerator_routineMap (const GALGAS_routineMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element cEnumerator_routineMap::current (LOCATION_ARGS) const {
  const cMapElement_routineMap * p = (const cMapElement_routineMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMap) ;
  return GALGAS_routineMap_2D_element (p->mProperty_lkey) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring cEnumerator_routineMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  @routineMap type                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_routineMap ("routineMap",
                                   NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_routineMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_routineMap ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_routineMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_routineMap (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap GALGAS_routineMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_routineMap result ;
  const GALGAS_routineMap * p = (const GALGAS_routineMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_routineMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("routineMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_start_5F_symbol_i0_ (C_Lexique_logo_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PROGRAM COMMA_SOURCE_FILE ("logo-syntax.galgas", 5)) ;
  GALGAS_routineMap var_tableRoutines_160 = GALGAS_routineMap::constructor_emptyMap (SOURCE_FILE ("logo-syntax.galgas", 7)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_logo_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_routine_5F_definition_ (var_tableRoutines_160, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_BEGIN COMMA_SOURCE_FILE ("logo-syntax.galgas", 13)) ;
  nt_instruction_5F_list_ (var_tableRoutines_160, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_END COMMA_SOURCE_FILE ("logo-syntax.galgas", 15)) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken__2E_ COMMA_SOURCE_FILE ("logo-syntax.galgas", 16)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_start_5F_symbol_i0_parse (C_Lexique_logo_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PROGRAM COMMA_SOURCE_FILE ("logo-syntax.galgas", 5)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_logo_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_routine_5F_definition_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_BEGIN COMMA_SOURCE_FILE ("logo-syntax.galgas", 13)) ;
  nt_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_END COMMA_SOURCE_FILE ("logo-syntax.galgas", 15)) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken__2E_ COMMA_SOURCE_FILE ("logo-syntax.galgas", 16)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_routine_5F_definition_i1_ (GALGAS_routineMap & ioArgument_ioTableRoutines,
                                                                            C_Lexique_logo_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_ROUTINE COMMA_SOURCE_FILE ("logo-syntax.galgas", 20)) ;
  GALGAS_lstring var_identifier_5F_id_432 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_identifier COMMA_SOURCE_FILE ("logo-syntax.galgas", 21)) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_BEGIN COMMA_SOURCE_FILE ("logo-syntax.galgas", 22)) ;
  nt_instruction_5F_list_ (ioArgument_ioTableRoutines, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_END COMMA_SOURCE_FILE ("logo-syntax.galgas", 24)) ;
  {
  ioArgument_ioTableRoutines.setter_insertKey (var_identifier_5F_id_432, inCompiler COMMA_SOURCE_FILE ("logo-syntax.galgas", 25)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_routine_5F_definition_i1_parse (C_Lexique_logo_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_ROUTINE COMMA_SOURCE_FILE ("logo-syntax.galgas", 20)) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_identifier COMMA_SOURCE_FILE ("logo-syntax.galgas", 21)) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_BEGIN COMMA_SOURCE_FILE ("logo-syntax.galgas", 22)) ;
  nt_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_END COMMA_SOURCE_FILE ("logo-syntax.galgas", 24)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_instruction_5F_list_i2_ (GALGAS_routineMap inArgument_ioTableRoutines,
                                                                          C_Lexique_logo_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_logo_5F_syntax_1 (inCompiler)) {
    case 2: {
      nt_instruction_ (inArgument_ioTableRoutines, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_instruction_5F_list_i2_parse (C_Lexique_logo_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_logo_5F_syntax_1 (inCompiler)) {
    case 2: {
      nt_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_instruction_i3_ (GALGAS_routineMap inArgument_ioTableRoutines,
                                                                  C_Lexique_logo_5F_lexique * inCompiler) {
  switch (select_logo_5F_syntax_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_FORWARD COMMA_SOURCE_FILE ("logo-syntax.galgas", 37)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_integer COMMA_SOURCE_FILE ("logo-syntax.galgas", 38)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_ROTATE COMMA_SOURCE_FILE ("logo-syntax.galgas", 40)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_integer COMMA_SOURCE_FILE ("logo-syntax.galgas", 41)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PEN COMMA_SOURCE_FILE ("logo-syntax.galgas", 43)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_UP COMMA_SOURCE_FILE ("logo-syntax.galgas", 44)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PEN COMMA_SOURCE_FILE ("logo-syntax.galgas", 46)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_DOWN COMMA_SOURCE_FILE ("logo-syntax.galgas", 47)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_CALL COMMA_SOURCE_FILE ("logo-syntax.galgas", 49)) ;
    GALGAS_lstring var_nomIden_869 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_identifier COMMA_SOURCE_FILE ("logo-syntax.galgas", 50)) ;
    inArgument_ioTableRoutines.method_searchKey (var_nomIden_869, inCompiler COMMA_SOURCE_FILE ("logo-syntax.galgas", 51)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("logo-syntax.galgas", 53)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_logo_5F_syntax::rule_logo_5F_syntax_instruction_i3_parse (C_Lexique_logo_5F_lexique * inCompiler) {
  switch (select_logo_5F_syntax_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_FORWARD COMMA_SOURCE_FILE ("logo-syntax.galgas", 37)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_integer COMMA_SOURCE_FILE ("logo-syntax.galgas", 38)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_ROTATE COMMA_SOURCE_FILE ("logo-syntax.galgas", 40)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_integer COMMA_SOURCE_FILE ("logo-syntax.galgas", 41)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PEN COMMA_SOURCE_FILE ("logo-syntax.galgas", 43)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_UP COMMA_SOURCE_FILE ("logo-syntax.galgas", 44)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_PEN COMMA_SOURCE_FILE ("logo-syntax.galgas", 46)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_DOWN COMMA_SOURCE_FILE ("logo-syntax.galgas", 47)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_CALL COMMA_SOURCE_FILE ("logo-syntax.galgas", 49)) ;
    inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken_identifier COMMA_SOURCE_FILE ("logo-syntax.galgas", 50)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_logo_5F_lexique::kToken__3B_ COMMA_SOURCE_FILE ("logo-syntax.galgas", 53)) ;
  inCompiler->resetTemplateString () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element::GALGAS_routineMap_2D_element (void) :
mProperty_lkey () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element::~ GALGAS_routineMap_2D_element (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element::GALGAS_routineMap_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_lkey (inOperand0) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element GALGAS_routineMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_routineMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element GALGAS_routineMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_routineMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_routineMap_2D_element (inOperand0) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult GALGAS_routineMap_2D_element::objectCompare (const GALGAS_routineMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool GALGAS_routineMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_routineMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_routineMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @routineMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring GALGAS_routineMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}



//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              @routineMap-element type                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_routineMap_2D_element ("routineMap-element",
                                              NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const C_galgas_type_descriptor * GALGAS_routineMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_routineMap_2D_element ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_root * GALGAS_routineMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_routineMap_2D_element (*this)) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_routineMap_2D_element GALGAS_routineMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_routineMap_2D_element result ;
  const GALGAS_routineMap_2D_element * p = (const GALGAS_routineMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_routineMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("routineMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       N O N    T E R M I N A L    N A M E S                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const char * gNonTerminalNames_logo_grammar [8] = {
  "<start_symbol>",// Index 0
  "<routine_definition>",// Index 1
  "<instruction_list>",// Index 2
  "<instruction>",// Index 3
  "<select_logo_5F_syntax_0>",// Index 4
  "<select_logo_5F_syntax_1>",// Index 5
  "<select_logo_5F_syntax_2>",// Index 6
  "<>"// Index 7
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              L R ( 1 )    A N A L Y Z E R    A C T I O N    T A B L E                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

// Action tables handle shift and reduce actions ;
//  - a shift action is (terminal_symbol, SHIFT (n)) : if shifts to state n ;
//  - the accept action is (terminal_symbol, ACCEPT) ;
//  - a reduce action is (terminal_symbol, REDUCE (n)) ; if reduces to state n.

#define SHIFT(a) ((a) + 2)
#define REDUCE(a) (-(a) - 1)
#define ACCEPT (1)
#define END (-1)

static const int16_t gActionTable_logo_grammar [] = {
// State S0 (index = 0)
  C_Lexique_logo_5F_lexique::kToken_PROGRAM, SHIFT (1)
, END
// State S1 (index = 3)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, REDUCE (4)
, C_Lexique_logo_5F_lexique::kToken_ROUTINE, SHIFT (3)
, END
// State S2 (index = 8)
, C_Lexique_logo_5F_lexique::kToken_, ACCEPT
, END
// State S3 (index = 11)
, C_Lexique_logo_5F_lexique::kToken_identifier, SHIFT (6)
, END
// State S4 (index = 14)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, REDUCE (4)
, C_Lexique_logo_5F_lexique::kToken_ROUTINE, SHIFT (3)
, END
// State S5 (index = 19)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, SHIFT (8)
, END
// State S6 (index = 22)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, SHIFT (9)
, END
// State S7 (index = 25)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, REDUCE (5)
, END
// State S8 (index = 28)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (6)
, C_Lexique_logo_5F_lexique::kToken_FORWARD, SHIFT (10)
, C_Lexique_logo_5F_lexique::kToken_ROTATE, SHIFT (11)
, C_Lexique_logo_5F_lexique::kToken_PEN, SHIFT (12)
, C_Lexique_logo_5F_lexique::kToken_CALL, SHIFT (13)
, END
// State S9 (index = 39)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (6)
, C_Lexique_logo_5F_lexique::kToken_FORWARD, SHIFT (10)
, C_Lexique_logo_5F_lexique::kToken_ROTATE, SHIFT (11)
, C_Lexique_logo_5F_lexique::kToken_PEN, SHIFT (12)
, C_Lexique_logo_5F_lexique::kToken_CALL, SHIFT (13)
, END
// State S10 (index = 50)
, C_Lexique_logo_5F_lexique::kToken_integer, SHIFT (19)
, END
// State S11 (index = 53)
, C_Lexique_logo_5F_lexique::kToken_integer, SHIFT (20)
, END
// State S12 (index = 56)
, C_Lexique_logo_5F_lexique::kToken_UP, SHIFT (21)
, C_Lexique_logo_5F_lexique::kToken_DOWN, SHIFT (22)
, END
// State S13 (index = 61)
, C_Lexique_logo_5F_lexique::kToken_identifier, SHIFT (23)
, END
// State S14 (index = 64)
, C_Lexique_logo_5F_lexique::kToken_END, SHIFT (24)
, END
// State S15 (index = 67)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (6)
, C_Lexique_logo_5F_lexique::kToken_FORWARD, SHIFT (10)
, C_Lexique_logo_5F_lexique::kToken_ROTATE, SHIFT (11)
, C_Lexique_logo_5F_lexique::kToken_PEN, SHIFT (12)
, C_Lexique_logo_5F_lexique::kToken_CALL, SHIFT (13)
, END
// State S16 (index = 78)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (2)
, END
// State S17 (index = 81)
, C_Lexique_logo_5F_lexique::kToken__3B_, SHIFT (26)
, END
// State S18 (index = 84)
, C_Lexique_logo_5F_lexique::kToken_END, SHIFT (27)
, END
// State S19 (index = 87)
, C_Lexique_logo_5F_lexique::kToken__3B_, REDUCE (8)
, END
// State S20 (index = 90)
, C_Lexique_logo_5F_lexique::kToken__3B_, REDUCE (9)
, END
// State S21 (index = 93)
, C_Lexique_logo_5F_lexique::kToken__3B_, REDUCE (10)
, END
// State S22 (index = 96)
, C_Lexique_logo_5F_lexique::kToken__3B_, REDUCE (11)
, END
// State S23 (index = 99)
, C_Lexique_logo_5F_lexique::kToken__3B_, REDUCE (12)
, END
// State S24 (index = 102)
, C_Lexique_logo_5F_lexique::kToken__2E_, SHIFT (28)
, END
// State S25 (index = 105)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (7)
, END
// State S26 (index = 108)
, C_Lexique_logo_5F_lexique::kToken_END, REDUCE (3)
, C_Lexique_logo_5F_lexique::kToken_FORWARD, REDUCE (3)
, C_Lexique_logo_5F_lexique::kToken_ROTATE, REDUCE (3)
, C_Lexique_logo_5F_lexique::kToken_PEN, REDUCE (3)
, C_Lexique_logo_5F_lexique::kToken_CALL, REDUCE (3)
, C_Lexique_logo_5F_lexique::kToken_, REDUCE (3)
, END
// State S27 (index = 121)
, C_Lexique_logo_5F_lexique::kToken_BEGIN, REDUCE (1)
, C_Lexique_logo_5F_lexique::kToken_ROUTINE, REDUCE (1)
, C_Lexique_logo_5F_lexique::kToken_, REDUCE (1)
, END
// State S28 (index = 128)
, C_Lexique_logo_5F_lexique::kToken_, REDUCE (0)
, END} ;

static const uint32_t gActionTableIndex_logo_grammar [29] = {
  0  // S0
, 3  // S1
, 8  // S2
, 11  // S3
, 14  // S4
, 19  // S5
, 22  // S6
, 25  // S7
, 28  // S8
, 39  // S9
, 50  // S10
, 53  // S11
, 56  // S12
, 61  // S13
, 64  // S14
, 67  // S15
, 78  // S16
, 81  // S17
, 84  // S18
, 87  // S19
, 90  // S20
, 93  // S21
, 96  // S22
, 99  // S23
, 102  // S24
, 105  // S25
, 108  // S26
, 121  // S27
, 128  // S28
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                            SLR states successors table                                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

// Successor tables handle non terminal successors ;
// an entry is (non_terminal_symbol, n) ; successor is state n.

static const int16_t gSuccessorTable_logo_grammar_0 [3] = {0, 2, -1} ;

static const int16_t gSuccessorTable_logo_grammar_1 [5] = {1, 4,
  4, 5, -1} ;

static const int16_t gSuccessorTable_logo_grammar_4 [5] = {1, 4,
  4, 7, -1} ;

static const int16_t gSuccessorTable_logo_grammar_8 [9] = {2, 14,
  3, 15,
  5, 16,
  6, 17, -1} ;

static const int16_t gSuccessorTable_logo_grammar_9 [9] = {2, 18,
  3, 15,
  5, 16,
  6, 17, -1} ;

static const int16_t gSuccessorTable_logo_grammar_15 [7] = {3, 15,
  5, 25,
  6, 17, -1} ;

static const int16_t * gSuccessorTable_logo_grammar [29] = {
gSuccessorTable_logo_grammar_0, gSuccessorTable_logo_grammar_1, NULL, NULL, 
  gSuccessorTable_logo_grammar_4, NULL, NULL, NULL, 
  gSuccessorTable_logo_grammar_8, gSuccessorTable_logo_grammar_9, NULL, NULL, 
  NULL, NULL, NULL, gSuccessorTable_logo_grammar_15, 
  NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, 
  NULL} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                          Production rules infos (left non terminal, size of right string)                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionsTable_logo_grammar [14 * 2] = {
  0, 6,
  1, 5,
  2, 1,
  3, 2,
  4, 0,
  4, 2,
  5, 0,
  5, 2,
  6, 2,
  6, 2,
  6, 2,
  6, 2,
  6, 2,
  7, 1
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'start_symbol' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_logo_5F_grammar::nt_start_5F_symbol_parse (C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 0 :
      rule_logo_5F_syntax_start_5F_symbol_i0_parse(inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

void cGrammar_logo_5F_grammar::nt_start_5F_symbol_ (C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 0 :
      rule_logo_5F_syntax_start_5F_symbol_i0_(inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

void cGrammar_logo_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_logo_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_logo_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_logo_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_logo_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_logo_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_logo_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performBottomUpParsing (gActionTable_logo_grammar, gNonTerminalNames_logo_grammar,
                                     gActionTableIndex_logo_grammar, gSuccessorTable_logo_grammar,
                                     gProductionsTable_logo_grammar) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_logo_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
      C_Lexique_logo_5F_lexique * scanner = NULL ;
      macroMyNew (scanner, C_Lexique_logo_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
      if (scanner->sourceText ().isValid ()) {
        const bool ok = scanner->performBottomUpParsing (gActionTable_logo_grammar, gNonTerminalNames_logo_grammar,
                                                         gActionTableIndex_logo_grammar, gSuccessorTable_logo_grammar,
                                                         gProductionsTable_logo_grammar) ;
        if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
          cGrammar_logo_5F_grammar grammar ;
          grammar.nt_start_5F_symbol_ (scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
        }
        macroDetachSharedObject (scanner) ;
      }else{
        C_String message ;
        message << "the '" << filePath << "' file does not exist" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

void cGrammar_logo_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_logo_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_logo_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performBottomUpParsing (gActionTable_logo_grammar, gNonTerminalNames_logo_grammar,
                                                     gActionTableIndex_logo_grammar, gSuccessorTable_logo_grammar,
                                                     gProductionsTable_logo_grammar) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_logo_5F_grammar grammar ;
      grammar.nt_start_5F_symbol_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'routine_definition' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_logo_5F_grammar::nt_routine_5F_definition_parse (C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
      rule_logo_5F_syntax_routine_5F_definition_i1_parse(inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

void cGrammar_logo_5F_grammar::nt_routine_5F_definition_ (GALGAS_routineMap &  parameter_1,
                                C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
      rule_logo_5F_syntax_routine_5F_definition_i1_(parameter_1, inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'instruction_list' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_logo_5F_grammar::nt_instruction_5F_list_parse (C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 2 :
      rule_logo_5F_syntax_instruction_5F_list_i2_parse(inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

void cGrammar_logo_5F_grammar::nt_instruction_5F_list_ (GALGAS_routineMap  parameter_1,
                                C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 2 :
      rule_logo_5F_syntax_instruction_5F_list_i2_(parameter_1, inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'instruction' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_logo_5F_grammar::nt_instruction_parse (C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 3 :
      rule_logo_5F_syntax_instruction_i3_parse(inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

void cGrammar_logo_5F_grammar::nt_instruction_ (GALGAS_routineMap  parameter_1,
                                C_Lexique_logo_5F_lexique * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 3 :
      rule_logo_5F_syntax_instruction_i3_(parameter_1, inLexique) ;
    break ;
  default :
    inLexique->internalBottomUpParserError (HERE) ;
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'select_logo_5F_syntax_0' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_logo_5F_grammar::select_logo_5F_syntax_0 (C_Lexique_logo_5F_lexique * inLexique) {
// Productions numbers : 4 5
  return inLexique->nextProductionIndex () - 3 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'select_logo_5F_syntax_1' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_logo_5F_grammar::select_logo_5F_syntax_1 (C_Lexique_logo_5F_lexique * inLexique) {
// Productions numbers : 6 7
  return inLexique->nextProductionIndex () - 5 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'select_logo_5F_syntax_2' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_logo_5F_grammar::select_logo_5F_syntax_2 (C_Lexique_logo_5F_lexique * inLexique) {
// Productions numbers : 8 9 10 11 12
  return inLexique->nextProductionIndex () - 7 ;
}

//---------------------------------------------------------------------------------------------------------------------*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileExtensions [] = {
  "logo",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileHelpMessages [] = {
  "a source text file with the .logo extension",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * projectVersionString (void) {
  return "0.0.1" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  cGrammar_logo_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("logo-program.galgas", 10)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonCompiler = NULL ;
    macroMyNew (commonCompiler, C_Compiler (NULL COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonCompiler->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "logo") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            cGrammar_logo_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            cGrammar_logo_5F_grammar::performOnlySyntaxAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeIndexing :
            cGrammar_logo_5F_grammar::performIndexing (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeLatex :
            cGrammar_logo_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}

