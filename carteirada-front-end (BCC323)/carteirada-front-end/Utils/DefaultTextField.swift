//
//  DefaultTextField.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 30/09/22.
//

import UIKit

class DefaultTextField: UITextField {

    required init?(coder aDecoder: NSCoder) {
       super.init(coder: aDecoder)
        self.layer.borderWidth = 0
        self.layer.borderColor = UIColor.black.cgColor
        self.layer.cornerRadius = 10
    }

}
