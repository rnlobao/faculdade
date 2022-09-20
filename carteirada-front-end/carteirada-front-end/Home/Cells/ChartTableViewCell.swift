//
//  ChartTableViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit

class ChartTableViewCell: UITableViewCell {

    @IBOutlet weak var chartBackground: UIView!
    
    
    func setupView() {
        chartBackground.layer.cornerRadius = 20
        chartBackground.layer.shadowColor = UIColor.black.cgColor
        chartBackground.layer.shadowOffset = CGSize(width: 0.0, height: 2.0)
        chartBackground.layer.shadowRadius = 4.0
        chartBackground.layer.shadowOpacity = 0.5
        chartBackground.layer.masksToBounds = false
    }
    
}
