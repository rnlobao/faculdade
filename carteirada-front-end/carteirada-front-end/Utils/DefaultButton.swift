//
//  DefaultButton.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 30/09/22.
//

import UIKit

final class DefaultButton: UIButton {
    
    private let myLabel: UILabel = {
        let label = UILabel()
        label.numberOfLines = 1
        label.textAlignment = .center
        label.textColor = UIColor.darkCarteiradaGreen()
        label.font = UIFont(name: "Poppins-Medium", size: 15)
        return label
    }()
    
    required init?(coder aDecoder: NSCoder) {
       super.init(coder: aDecoder)
        self.addSubview(myLabel)
        self.clipsToBounds = true
        self.layer.cornerRadius = 10
        self.layer.borderWidth = 1
        self.layer.borderColor = UIColor.darkCarteiradaGreen().cgColor
        self.setTitle("", for: .normal)
        
    }
    
    func configure(whatsInside: String) {
        myLabel.text = whatsInside
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        myLabel.frame = CGRect(x: 0, y: 0, width: frame.size.width, height: frame.size.height)
    }

}
