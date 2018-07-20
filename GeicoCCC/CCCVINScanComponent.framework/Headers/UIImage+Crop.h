//
//  UIImage+Crop.h


#import <UIKit/UIKit.h>

@interface UIImage(CropCategory)
- (UIImage *)crop:(CGRect)rect;
- (UIImage *)squareImageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
- (UIImage *)croppIngimageByImageName:(UIImage *)imageToCrop toRect:(CGRect)rect;
- (UIImage *)cropImage:(UIImage*)image andFrame:(CGRect)rect;
- (UIImage *)crop:(UIImage *)image inRect:(CGRect)cropRect;
- (UIImage *)imageWithImage:(UIImage *)image cropInRect:(CGRect)rect ;
@end
