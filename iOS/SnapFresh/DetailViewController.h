/*
 * Copyright 2012 Marco Abundo, Ysiad Ferreiras, Aaron Bannert, Jeremy Canfield and Michelle Koeth
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import "IASKAppSettingsViewController.h"

@protocol DetailViewControllerDelegate;

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate, 
                                                    UISearchBarDelegate, 
                                                    MKMapViewDelegate,
                                                    NSXMLParserDelegate,
                                                    IASKSettingsDelegate>
{
    NSMutableArray *_retailers;
    dispatch_queue_t dispatchQueue;
}

@property (nonatomic, weak) id <DetailViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet MKMapView *mapView;
@property (nonatomic, strong, readonly) NSArray *retailers;

@end

/**
 * A delegate implements this protocol to be notified when the map is finished loading.
 */
@protocol DetailViewControllerDelegate
- (void)annotationsDidLoad:(DetailViewController *)controller;
@end
