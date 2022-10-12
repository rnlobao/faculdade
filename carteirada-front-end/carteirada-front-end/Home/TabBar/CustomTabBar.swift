//
//  CustomTabBar.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import UIKit

class CustomTabBar: UITabBarController, UITabBarControllerDelegate {
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.selectedIndex = 1
    }
}
