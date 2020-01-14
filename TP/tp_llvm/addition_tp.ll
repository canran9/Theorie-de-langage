target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

define zeroext i3 @myUnsignedAddition (i3 zeroext %a, i3 zeroext %b) nounwind { 
      %res = add nsw i3 %a, %b
      ret i3 %res
}

define signext i23 @mySignedAddition (i23 signext %a, i23 signext %b) nounwind { 
          %res = add nsw i23 %a, %b
          ret i23 %res
}

define zeroext i23 @multiplicationUnsigned (i23 zeroext %a, i23 zeroext %b) nounwind { 
      %res = mul nsw i23 %a, %b
      ret i23 %res
}

define signext i23 @multiplicationSigned (i23 signext %a, i23 signext %b) nounwind { 
          %res = mul nsw i23 %a, %b
          ret i23 %res
}


