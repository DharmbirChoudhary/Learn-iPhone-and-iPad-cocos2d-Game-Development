/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2008-2010 Ricardo Quesada
 * Copyright (c) 2009 Jason Booth
 * Copyright (c) 2009 Robert J Payne
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */


/*
 * To create sprite frames and texture atlas, use this tool:
 * http://zwoptex.zwopple.com/
 */

#import <Foundation/Foundation.h>

#import "CCSpriteFrame.h"
#import "CCTexture2D.h"

@class CCSprite;

/** Singleton that handles the loading of the sprite frames.
 It saves in a cache the sprite frames.
 @since v0.9
 */
@interface CCSpriteFrameCache : NSObject {

	NSMutableDictionary *spriteFrames;
}

/** Retruns ths shared instance of the Sprite Frame cache */
+ (CCSpriteFrameCache *) sharedSpriteFrameCache;

/** Purges the cache. It releases all the Sprite Frames and the retained instance.
 */
+(void)purgeSharedSpriteFrameCache;


/** Adds multiple Sprite Frames with a dictionary. The texture will be associated with the created sprite frames.
 */
-(void) addSpriteFramesWithDictionary:(NSDictionary*)dictionary texture:(CCTexture2D*)texture;

/** Adds multiple Sprite Frames from a plist file.
 * A texture will be loaded automatically. The texture name will composed by replacing the .plist suffix with .png
 * If you want to use another texture, you should use the addSpriteFramesWithFile:texture method.
 */
-(void) addSpriteFramesWithFile:(NSString*)plist;

/** Adds multiple Sprite Frames from a plist file. The texture will be associated with the created sprite frames.
 */
-(void) addSpriteFramesWithFile:(NSString*)plist texture:(CCTexture2D*)texture;

/** Adds an sprite frame with a given name.
 If the name already exists, then the contents of the old name will be replaced with the new one.
 */
-(void) addSpriteFrame:(CCSpriteFrame*)frame name:(NSString*)frameName;


/** Purges the dictionary of loaded sprite frames.
 * Call this method if you receive the "Memory Warning".
 * In the short term: it will free some resources preventing your app from being killed.
 * In the medium term: it will allocate more resources.
 * In the long term: it will be the same.
 */
-(void) removeSpriteFrames;

/** Removes unused sprite frames.
 * Sprite Frames that have a retain count of 1 will be deleted.
 * It is convinient to call this method after when starting a new Scene.
 */
-(void) removeUnusedSpriteFrames;

/** Deletes an sprite frame from the sprite frame cache.
 */
-(void) removeSpriteFrameByName:(NSString*)name;

/** Returns an Sprite Frame that was previously added.
 If the name is not found it will return nil.
 You should retain the returned copy if you are going to use it.
 */
-(CCSpriteFrame*) spriteFrameByName:(NSString*)name;

/** Creates an sprite with the name of an sprite frame.
 The created sprite will contain the texture, rect and offset of the sprite frame.
 It returns an autorelease object.
 @deprecated use [CCSprite spriteWithSpriteFrameName:name]. This method will be removed on final v0.9
 */
-(CCSprite*) createSpriteWithFrameName:(NSString*)name __attribute__((deprecated));

@end
