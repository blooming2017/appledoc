//
//  GBStoreProviding.h
//  appledoc
//
//  Created by Tomaz Kragelj on 25.7.10.
//  Copyright 2010 Gentle Bytes. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GBClassData;
@class GBCategoryData;
@class GBProtocolData;

/** Defines the requirements for store providers.
 
 Store providers are objects handling the storage of in-memory representations of parsed objects.
 */
@protocol GBStoreProviding

///---------------------------------------------------------------------------------------
/// @name Registrations handling
///---------------------------------------------------------------------------------------

/** Registers the given class to the providers data.
 
 If provider doesn't yet have the given class instance registered, the object is added to `classes` list. If the same object is already registered, nothing happens.
 
 @warning *Note:* If another instance of the class with the same name is registered, an exception is thrown.
 
 @param class The class to register.
 @exception NSException Thrown if the given class is already registered.
 @see registerCategory:
 @see registerProtocol:
 @see unregisterTopLevelObject:
 @see classWithName:
 @see classes
 */
- (void)registerClass:(GBClassData *)class;

/** Registers the given category to the providers data.
 
 If provider doesn't yet have the given category instance registered, the object is added to `categories` list. If the same object is already registered, nothing happens.
 
 @warning *Note:* If another instance of the category with the same name/class name is registered, an exception is thrown.
 
 @param category The category to register.
 @exception NSException Thrown if the given category is already registered.
 @see registerClass:
 @see registerProtocol:
 @see unregisterTopLevelObject:
 @see categoryWithName:
 @see categories
 */
- (void)registerCategory:(GBCategoryData *)category;

/** Registers the given protocol to the providers data.
 
 If provider doesn't yet have the given protocol instance registered, the object is added to `protocols` list. If the same object is already registered, nothing happens.
 
 @warning *Note:* If another instance of the protocol with the same name name is registered, an exception is thrown.
 
 @param protocol The protocol to register.
 @exception NSException Thrown if the given protocol is already registered.
 @see registerClass:
 @see registerCategory:
 @see unregisterTopLevelObject:
 @see protocolWithName:
 @see protocols
 */
- (void)registerProtocol:(GBProtocolData *)protocol;

/** Unregisters the given class, category or protocol.
 
 If the object is not part of the store, nothing happens.
 
 @param object The object to remove.
 @see registerClass:
 @see registerCategory:
 @see registerProtocol:
 */
- (void)unregisterTopLevelObject:(id)object;

///---------------------------------------------------------------------------------------
/// @name Data handling
///---------------------------------------------------------------------------------------

/** Returns the class instance that matches the given name.
 
 If no registered class matches the given name, `nil` is returned.
 
 @param name The name of the class to return.
 @return Returns class instance or `nil` if no match is found.
 @see categoryWithName:
 @see protocolWithName:
 @see classes
 */
- (GBClassData *)classWithName:(NSString *)name;

/** Returns the category instance that matches the given name.
 
 If no registered category matches the given name, `nil` is returned.
 
 @param name The name of the category to return.
 @return Returns category instance or `nil` if no match is found.
 @see classWithName:
 @see protocolWithName:
 @see categories
 */
- (GBCategoryData *)categoryWithName:(NSString *)name;

/** Returns the protocol instance that matches the given name.
 
 If no registered protocol matches the given name, `nil` is returned.
 
 @param name The name of the protocol to return.
 @return Returns protocol instance or `nil` if no match is found.
 @see classWithName:
 @see categoryWithName:
 @see protocols
 */
- (GBProtocolData *)protocolWithName:(NSString *)name;

/** The list of all registered classes as instances of `GBClassData`.
 
 @see classWithName:
 @see registerClass:
 */
@property (readonly) NSSet *classes;

/** The list of all registered categories and extensions as instances of `GBCategoryData`.
 
 @see categoryWithName:
 @see registerCategory:
 */
@property (readonly) NSSet *categories;

/** The list of all registered protocols as instances of `GBProtocolData`.
 
 @see protocolWithName:
 @see registerProtocol:
 */
@property (readonly) NSSet *protocols;

///---------------------------------------------------------------------------------------
/// @name Helper methods
///---------------------------------------------------------------------------------------

/** Returns all registered classes sorted by their name. */
- (NSArray *)classesSortedByName;

/** Returns all registered categories sorted by their name. */
- (NSArray *)categoriesSortedByName;

/** Returns all registered protocols sorted by their name. */
- (NSArray *)protocolsSortedByName;

@end
